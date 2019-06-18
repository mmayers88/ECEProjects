makefile:
  The Make file uses commands capture and end, to create their respective programs.
You can also use MAKEALL to create all of the executables and CLEARALL to remove
the executables as well as the .o files.



end:
  end works by entering the name of the .txt file and then the last number of lines
that you want to see from the file.  It checks to make sure that the file isn't
empty and that the correct number of lines are put in.  If no lines are entered,
then the default is 5 lines that it will print.  I open the file, and I read 10
chars at a time.  If it's not an empty file it searches through the 10 chars
looking for return carriage or a new line.  If any of those are found it
will commit whatever came before to be saved to the buffer.  If the line was only
a newline, I assume that the line is empty and it's skipped.
  At each 10 read interval, if the program has not found a newline, it adds the
contents to a saveBuff, which is a string of max 1000 chars. If the line is
bigger, an error occurs.  If it is not bigger, the lines is saved to the buffer
and everything is returned to start reading a new line.  The data is save to a
circular buffer of some total size, that were defined as 9.  As the read
increments through through the file a line at a time, the new lines read in are
saved to the oldest line, this function is recycled from my last assignment.
  I modified my history function as well, and it writes the last n lines out to
the command line.



capture:
  Capture uses the same process to parse through the files. The saveBuff instead
gets tokenized, into a maximum of 10 commands. This makes it easier to through
into the execv function I use to run the commands.
  The biggest difference is that instead of saving a line, the process forks, if
successful, the child  will dup the stdout to the file .txt, which it will create
if it doesn't already exist.  The tokens are then put into the execv function
and the output is saved to the capture.txt file.  If unsuccessful an error is
returned.

endHelp:
  endHelp Contains reworked functions from the first assignment.  I was originally
going to house most of my functions in it, but I kept having problems trying to
run the program that I ended up putting everything in main to debug.  The problem
ended up being that I was using mingw32, which doesn't support using execv and
fork, so I later changed to cygwin.  
