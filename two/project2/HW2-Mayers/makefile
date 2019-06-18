OBJS = endHelp.o end.o

capture : capture.o endHelp.o
	gcc capture.o endHelp.o -o capture
end : $(OBJS)
	gcc $(OBJS) -o end
capture.o : capture.c
	gcc capture.c -c
endHelp.o : endHelp.c
	gcc endHelp.c -c
end.o : end.c
	gcc end.c -c
CLEAR:
	rm $(OBJS) end.exe
RUN : end
	./end
CLEARCAP:
	rm capture.o capture.exe
MAKEALL : capture.o endHelp.o end.o
	gcc capture.o endHelp.o -o capture
	gcc $(OBJS) -o end
CLEARALL :
	rm capture.o capture.exe
	rm $(OBJS) end.exe
