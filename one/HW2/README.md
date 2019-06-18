# ECE 361 Homework #2 --Comparing sort algorithms
## <i>This assignment will be worth 100 points and is due by 10:00 PM on Tuesday 16-Oct-2018</i>  

### After completing this assignment students should have:
- coded several sort algorithms in C
- gathered information on the efficiency of the different sort algorithms on different data sets
- gained experience compiling and executing a multiple module program under GCC

## Links to sort algorithm animations

Bubble Sort: https://www.youtube.com/watch?v=NiyEqLZmngY&t=18s

Selection Sort: https://www.youtube.com/watch?v=EdUWyka7kpI

Insertion Sort: https://www.youtube.com/watch?v=3TWBrA3FrYs

### Introduction

In this assignment we will be writing, compiling, and executing C code for three different sort algorithms - the Bubble sort, the Selection sort, and the Insertion sort.  We discussed all three of these algorithms in class and studied their performance.  Even though all three sort algorithms are O(N^2) there are performance differences in the number of steps to complete the sort.  As we learned in class, the number of steps to complete the sort is somewhat dependent on the size and initial ordering of the data.  For example, all three algorithms have their worst performance on arrays where the initial order is the reverse of the desired sort order.  That is, if our goal is to sort the array in ascending order, starting with an array that is perfectly ordered in descending order will likely (with these algorithms) take more steps than starting with an array that is already sorted in ascending order. Sorting algorithms for arrays that are  ordered randomly will (at least that's what we're hypothesizing) perform differently under different algorithms.  

You will submit your work via a private repository using GitHub classroom.  Our plan is to review your work and provide feedback using GitHub classroom but this will be a new experience for us so we'll see how it goes.

NOTES:
-  If you decide to leverage (borrow) existing code for your sort algorithms than please acknowledge the source.  You are encouraged, however, to create original code since that is the best way to learn.  We know how to use Google, too, so copying existing code from the web without acknowledging the source will lead to serious consequences if you are caught cheating.

- You may collaborate with your classmates in the design of the program but your are all expected to submit original work.  There is a difference between collaboration and copying - you don't want to be caught doing the latter since that could affect both your final grade and the grade of the student you copied from.

### Assignment:

* Part 1 (15 pts) - Write a C source code module call bubblesort.c that performs a Bubble sort on a fixed size array.  Provide a header file (bubblesort.h) so that your bubble sort function can be called from an external program.   Define a symbol called BS_VERBOSE and use conditional compilation (#ifdef..#endif) to enable and disable reporting of diagnostic information as the sort proceeds.  You can model this information on the information about each passthrough that is present in the starter code (a working Bubble Sort program) provided with the assignment.  bubblesort.c should implement a function with the following prototype:
      int  bubbleSort(int arr[], int size, int* ncompares_ptr, int* nswaps_ptr);
where arr[] is the integer array to sort, size is the number of elements in the array and ncompares__ptr and nswaps_ptr are pointers to int variables that will be written with the total number of compares performed and the total number of swaps performed to complete the sort.  The function should return an integer containing the total number of steps (compares + swaps) required to sort the array.

* Part 2 (15 pts) - Write a C source code module called selectionsort.c that performs a Selection sort on a fixed size array.  Provide a header file (selectionsort.h) so that your selection sort function can be called from an external program.   Define a symbol called SS_VERBOSE and use conditional compilation (#ifdef..#endif) to enable and disable reporting of diagnostic information as the sort proceeds.  You can model this information on the information about each passthrough that is present in the starter code (a working Bubble Sort program).  insertionsort.c should implement a function with the following prototype:
      int  selectionSort(int arr[], int size, int* ncompares_ptr, int* nswaps_ptr);
where arr[] is the integer array to sort, size is the number of elements in the array and ncompares__ptr and nswaps_ptr are pointers to int variables that will be written with the total number of compares performed and the total number of swaps performed to complete the sort.  The function should return an integer containing the total number of steps (compares + swaps) required to sort the array.

* Part 3 (15 pts) - Write a C source code module called insertionsort.c that performs an Insertion sort on a fixed size array.  Provide a header file (insertionsort.h) so that your insertion sort function can be called from an external program.   Define a symbol called IS_VERBOSE and use conditional compilation (#ifdef..#endif) to enable and disable reporting of diagnostic information as the sort proceeds.  You can model this information on the information about each passthrough that is present in the starter code (a working Bubble Sort program).  insertionsort.c should implement a function with the following prototype:
      int  insertionSort(int arr[], int size, int* ncompares_ptr, int* nswaps_ptr);
where arr[] is the integer array to sort, size is the number of elements in the array and ncompares__ptr and nswaps_ptr are pointers to int variables that will be written with the total number of compares performed and the total number of swaps performed to complete the sort.  The function should return an integer containing the total number of steps (compares + swaps) required to sort the array.

* Part 4 (35 pts) Write a C source code module called hw2.c that puts your sort functions to work.  hw2.c should define 3 arrays  at least 15 integers long.  Each of the arrays should contain the same integers but the initial sort order should vary.  One of the arrays should arrange the numbers in ascending order.  One of the arrays should arrange the numbers n descending order.  The third array should arrange the numbers in a random order (you get to define what "random" is).  The main() function in hw2.c should call each of the sort functions on each of the data sets (9 cases in all) and keep a tally of the results (number of compares and number of swaps) from each sort.  Once the program has gathered results from all of the test cases it should display a comparison of the results.

* Part 4 (20 pts) Compile, debug, and execute your program using the gcc tool suite for your host environment. Include at least one case with VERBOSE reporting turned on.  Remember, you can use the -D<i>name</i> option from the gcc command line to define and undefine the VERBOSE symbol.  You may use a Makefile for this project if you are familiar with <i>make</i>, but it is not required.

## Deliverables
- final source code for all of your modules
- a transcript (console log) showing the steps you followed to compile and execute the program.  The transcript should also include the results of the comparison.  

All of your development work should be done using Git and GitHub for version control.  Submit your final code and transcript by pushing the repository to the master branch of your GitHub repository for the assignment.
