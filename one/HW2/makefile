OBJS = hw2.o bubblesort.o selectionsort.o insertionsort.o

hw2 : hw2.o bubblesort.o selectionsort.o insertionsort.o
	gcc  $(OBJS) -o hw2
hw2.o: hw2.c
		gcc hw2.c -c
bubblesort.o : bubblesort.c
	gcc bubblesort.c -c
selectionsort.o : selectionsort.c
	gcc selectionsort.c -c
insertionsort.o : insertionsort.c
	gcc insertionsort.c -c
CLEAR:
	rm bubblesort.o selectionsort.o insertionsort.o
