TUI-OBJS = tui.o diceroll.o ascii_nums.o character_creator.o logos.o stats.o
DR-OBJS = rolldice.o diceroll.o logos.o ascii_nums.o
CFLAGS = -Wall -g
CC = g++
INCLUDE =
LIBS = -lncurses

all: tui rolldice

tui: ${TUI-OBJS}
	${CC} ${CFLAGS} ${INCLUDES} -o $@ ${TUI-OBJS} ${LIBS}

rolldice: ${DR-OBJS}
	${CC} ${CFLAGS} ${INCLUDES} -o $@ ${DR-OBJS} ${LIBS}

clean:
	rm *.o tui rolldice

.cpp.o:
	${CC} ${CFLAGS} ${INCLUDES} -c $<
