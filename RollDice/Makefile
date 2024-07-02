OBJS = rolldice.o ../src/diceroll.o
CFLAGS = -Wall -g
CC = g++
INCLUDE = ../include/
LIBS =

rolldice: ${OBJS}
	${CC} ${CFLAGS} ${INCLUDES} -o $@ ${OBJS} ${LIBS}

clean:
	rm *.o rolldice
.cpp.o:
	${CC} ${CFLAGS} ${INCLUDES} -c $<
