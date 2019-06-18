OBJS = shellFunc.o shell.o
READFILE = readme.txt
VARIABLE=`cat $(READFILE)`

shell : $(OBJS)
	gcc $(OBJS) -o shell
shellFunc.o : shellFunc.c
	gcc shellFunc.c -c
shell.o : shell.c
	gcc shell.c -c
CLEAR:
	rm $(OBJS) shell.exe
RUN : shell
	./shell
