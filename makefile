FILE=main.c
CC=gcc 
FLAGS=-Wall -g 
GNUFLAGS=-std=gnu2x
STDFLAGS=-std=c2x
COMPILE=cc.o
BIN=main

main: ${COMPILE}
	$(CC) ${COMPILE} -o bin/${BIN}

cc.o: $(FILE)	
	$(CC) -c $(FILE) $(FLAGS) -o cc.o 

gnucc.o: $(FILE)	
	$(CC) -c $(FILE) $(FLAGS) $(GNUFLAGS) -o gnucc.o 

stdcc.o: $(FILE)	
	$(CC) -c $(FILE) $(FLAGS) $(STDFLAGS) -o stdcc.o 

clean: 
	@touch test.o 
	rm *.o 
