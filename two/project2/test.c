#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include<errno.h>

void main(int argc, char *argv[])
{
int fd = 0;
 int errnum;
  fd =  execl("/bin/ls", "/bin/ls",  "-l", (char *) 0);
    if(fd == -1)
    {
      errnum = errno;
      fprintf(stderr, "Value of errno: %d\n", errno);
      perror("Error printed by perror");
      fprintf(stderr, "Error opening file: %s\n", strerror( errnum ));
    }
strerror(errno);
    return;
}
