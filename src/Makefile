OBJS = tui.o diceroll.o ascii_nums.o character_creator.o logos.o
CFLAGS = -Wall -g
CC = g++
INCLUDE =
LIBS = -lncurses

tui: ${OBJS}
	${CC} ${CFLAGS} ${INCLUDES} -o $@ ${OBJS} ${LIBS}

clean:
	rm *.o tui

.cpp.o:
	${CC} ${CFLAGS} ${INCLUDES} -c $<
