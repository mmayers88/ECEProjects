OBJS = stacksAndQueues.o queue.o stack.o

stacksAndQueues : $(OBJS)
	gcc $(OBJS) -o stacksAndQueues
stacksAndQueues.o : stacksAndQueues.c
	gcc stacksAndQueues.c -c
stack.o : stack.c
	gcc stack.c -c
queue.o : queue.c
	gcc queue.c -c
CLEAR:
	rm $(OBJS) stacksAndQueues.exe
LOGOUT: stacksAndQueues
	./stacksAndQueues > SaQtranscript.txt
