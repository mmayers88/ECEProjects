OBJS = sortHelp.o sort.o

sort : $(OBJS)
	gcc $(OBJS) -o sort
part1 : part1.o sortHelp.o
	gcc part1.o sortHelp.o -o part1
part1.o : part1.c
	gcc part1.c -c
sort.o : sort.c
	gcc sort.c -c
sortHelp.o : sortHelp.c
	gcc sortHelp.c -c
CLEAR:
	rm $(OBJS) sort.exe
RUN : sort
	./sort
CLEARALL :
	rm $(OBJS) sort.exe
	rm part1.o part1.exe
