#include "endHelp.h"

int main(int argc, char *argv[]) //filename and then number
{
	int fd;
	char fileName[FILEMAX];
	strcpy(fileName, argv[1]);
	int n = 5;
	bufferInfo circBuff[TOTALBUFF];
	char line[10];
	char saveLine[MAXCHAR];
	int currentPosition = 0; // current line number
	int charInLine = 0;	// number of chars in line, should be 1K
	int charRead = 0;	//char reading, should be 10 or less
	long long filePosition = 0;	//position in line
	int currentLine = 1;
	bool found = false;


	initBuff(circBuff);

	if (argc > 3 || argc <= 1)				//looking for the right number of arguments
	{
		write(STDOUT_FILENO, "error!", 7);
		return -1;
	}
	else if (argc == 3)					   //checking for number, else uses default
		n = atoi(argv[2]);

	if (n > 10 || n < 1)					//check if the number is between 0 and 11
	{
		write(STDOUT_FILENO, "error!", 7);
		return -1;
	}

	fd = open(fileName, O_RDONLY); // open file

	if (fd < 0)					  // check if valid
	{
		write(1, "error!", 7);
		return -1;
	}
	do
	{
		do {
			charInLine = read(fd, line, 10); // read line
			filePosition += charInLine;
			if (charInLine < 0)					  // check if valid
			{
				write(STDOUT_FILENO, "error!", 15);
				return -1;
			}
			if (filePosition == 0)
			{
				write(STDOUT_FILENO, "error! EMPTY", 13);  // if empty fail
				return -1;
			}

			int i = 0; // counter
			found = false; // logic if found
			if (charInLine != 0)
			{
				do
				{
					if (line[i] == '\n' || line[i] == '\t' || line[i] == '\r' || line[i] == EOF || line[i] == '\0') // chars to look for
					{
						line[i] = '\0';
						saveLine[charRead] = line[i];
						found = true;
						currentPosition++;
					}
					else									// keep moving until found
					{
						saveLine[charRead] = line[i];
						charRead++;
						i++;
						currentPosition++;
					}
				} while (i < charInLine && found != true);
			}
		} while (charRead < MAXCHAR && charInLine != 0 && found != true);
		if (charRead >= MAXCHAR) // only if the line is more than 1k chars
		{
			write(1, "error! Too Big", 7);
			return -1;
		}
		if (found == true)
		{
			if (saveLine[0] != '\0')		//saves line to buffer
			{
				char * token = strtok(saveLine, "\0");
				strcpy(saveLine, token);
				saveLine[strlen(saveLine) + 1] = '\0';
				savebuff(saveLine, currentLine, circBuff);
				currentLine++;
				memset(saveLine, '\0', strlen(saveLine));
			}
			charRead = 0;
			lseek(fd, filePosition - (filePosition - currentPosition) + 1, SEEK_SET);
			filePosition = currentPosition;
		}
	} while (charInLine != 0);


	if (saveLine[0] != '\0')    // final save
	{
		char * token = strtok(saveLine, "\0");
		strcpy(saveLine, token);
		saveLine[strlen(saveLine) + 1] = '\0';
		savebuff(saveLine, currentLine, circBuff);
	}


	if (charInLine == 0)			//if not blank, it prints
	{
		history(circBuff, currentLine, n);
	}
	return 0;
}
