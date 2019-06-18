#include "endHelp.h"

int main(int argc, char *argv[]) //filename and then number
{
	if (argc != 2)		// only take in one file
	{
		write(1, "error! Only one file location", 30);
		return -1;
	}
	int fd;
	int fd2;
	char saveFile[FILEMAX] = "capture.txt";
	char fileName[FILEMAX];
	char line[MAXCHAR];
	char saveLine[MAXCHAR];
	int currentPosition = 0; // current line number
	int charInLine = 0;	// number of chars in line, should be 1K
	int charRead = 0;	//char reading, should be 10 or less
	int currentCharRead = 0; //number read for offset
	long filePosition = 0;	//position in line
	int currentLine = 1;
	bool found = false;
	char * token[10];
	char * tokenPath;
	int tokenNum = 0;
	int errorCheck;

	strcpy(fileName, argv[1]);
	fd = open(fileName, O_RDONLY); // open file

	if (fd < 0)					  // check if valid
	{
		write(STDOUT_FILENO, "error!1", 8);
		return -1;
	}
	do
	{
		do {

			charInLine = read(fd, line, 10); // read line
			filePosition += charInLine;
			if (charInLine < 0)					  // check if valid
			{
				write(STDOUT_FILENO, "error!3", 8);
				return -1;
			}
			if (filePosition == 0)			//check if empty
			{
				write(STDOUT_FILENO, "error! EMPTY", 13);
				return -1;
			}
			int i = 0;
			found = false;
			if (charInLine != 0)
			{
				do
				{
					if (line[i] == '\n' || line[i] == '\t' || line[i] == '\r' || line[i] == EOF)		//chars to look for
					{
						line[i] = '\0';
						saveLine[charRead] = line[i];
						found = true;
						currentPosition++;
					}
					else			// if not found keep moving through file
					{
						saveLine[charRead] = line[i];
						charRead++;
						i++;
						currentPosition++;
					}
				} while (i < charInLine && found != true);
			}
		} while (charRead < MAXCHAR && charInLine != 0 && found != true);
		if (charRead >= MAXCHAR)			//only if line is more than 1000 chars
		{
			write(STDOUT_FILENO, "error! Too Big", 15);
			return -1;
		}
		if (found == true)				// create the command
		{
			if (saveLine[0] != '\0')
			{
				tokenNum = 0;
				for (int i = 0; i < 10; i++)
					token[i] = NULL;
				tokenPath = strtok(saveLine, " ");
				token[0] = tokenPath;
				while (tokenNum < 9 && token != NULL)
				{
					tokenNum++;
					token[tokenNum] = strtok(NULL, " ");
				}
				if (fork() == 0)				//fork, if child, run the execv code
				{
					int fd2 = open(saveFile, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);

					dup2(fd2, STDOUT_FILENO);   // make stdout go to file
					dup2(fd2, STDERR_FILENO);   // make stderr go to file
					// ^^^turning this off lets the errors appear to user 

					close(fd2);     // fd no longer needed

					errorCheck = execv(tokenPath, token);

					if (errorCheck < 0)							// if failure in execv
					{
						write(STDOUT_FILENO, "error! in execv", 15);
						return -1;
					}
				}
			}
			charRead = 0;
			lseek(fd, filePosition - (filePosition - currentPosition) + 1, SEEK_SET);  // back to correct read position
			filePosition = currentPosition;
		}
	} while (charInLine != 0);
}
