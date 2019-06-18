Mikhail Mayers
1/16/2019
ECE 362
Project 1

*In General*
struct bufferInfo:
  This program uses a struct called bufferInfo.  It contains two forms of data,
  an integer number that holds the line number of when added to the buffer and
  a char array words, that holds the text data to be saved.
main:
  I create and initialize(with function) my array of bufferInfo. I set my initial
  line number to 1.
  Main is fairly simple, it has an infinite while loop that displays the simple
  prompt "# >" and then takes in a data with fgets.  I chose fgets because
  because scanf needs a finite amount of string variables to take in, and I
  wanted to be able to take in a variable number of strings that I could tokenize.
  There is a limit to the number of char characters I can take in, that I
  arbitrarily made 80.
  Before I go into the functions, where all the real work
  is done,  I change the last character of the buffer to "/0"(null character)
  because I noticed the buffer ends with a "/n"(newline character) from when I
  entered it in. I don't know if that matters, but I didn't want to take a chance.
  It won't do this however, if only the enter button was pressed, because would
  create an error. Next the funtions, I use the output of my useCondition
  function to decide whether or not my lines increment, but inside of the
  usecondition, I checkCondition in order to find what command I want to use.
  Everthing else happens in my functions in shellFunc.


*Functions*

initBuff:
  InitBuff sets all of the initial num(line numbers) to 0, and the words
  (buffer string) to "N/A", in an array of bufferInfos.  I use this later in
  order to choose whether to print or not.
checkCondition:
  Check condition takes in a char array(buffer) from the user and decides what
  to do with it.  If it's an error, it gets 0, will get a 0 if nothing is entered.
  I tokenize the first part of the buffer with strtok and then I check the first
  character.  If the first charactersis "!" I check I shift the char array by
  one, and I check, getting rid of "!" and then I check if the token is a number
   with atoi. If success, then return1, else a 0.
  Then I check if the token is "parse", and if it is, I tokenize again and to see
  if there's a char following "parse", if successful return 2, else a 0;
  Then I check for "exit" and return 3 if successful, check "history" and return
  4 if successful, and anything else by default just returns a 5.
useCondition:
  I use the number returned from checkCondition to use my switch statement.  The
  switch statement controls what functiion runs.  If the function fails, it will
  return a false which will send back a failure message and also return a false
  which won't increment the line number, except for exit, which just uses the
  signals.h exit function. If they work, the all return true, except for exit,
  and they all save to the bufferInfoList except for bang, which saves later.
  Case 5 doesn't do anything except save the given string.
failure:
  Just a failure message.
savebuff:
  This saves the data to the bufferInfo array.  I use mods in order to keep track
  of which index to save to. this is a passive way to increment my bufferInfos
  list.
bang:
  This one is by far my most complicated.  It checks at various stages to make
  sure that the number you are looking for is in the array.  It checks that the
  number requested isn't bigger than the current line number,  that the number is
  in the buffer list by checking it against bufferInfo.num.  If it finds it in
  any of the stages, it uses a call similar to the one in main, which will also
  save the data from the buffer in the current bufferInfoList spot.
history:
  This basically just prints the list, unless the lineNum less than or equal to
  num.  This also ignores any bufferInfos that have initial values.
parse:
  This tokenizes the string given, as shown in class.  I just used strtok and
  a while loop that runs until the end of the string.
