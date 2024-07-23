TUI-OBJS = tui.o name_generator.o diceroll.o ascii_nums.o character_creator.o logos.o stats.o export.o equipment.o
DR-OBJS = rolldice.o diceroll.o logos.o ascii_nums.o
CFLAGS = -Wall -g
CC = g++
INCLUDE = -I../include -I/usr/local/include
LIBS = -lncurses -lOpenXLSX

all: tui rolldice namegen

tui: ${TUI-OBJS}
	${CC} ${CFLAGS} ${INCLUDE} -o $@ ${TUI-OBJS} ${LIBS}

rolldice: ${DR-OBJS}
	${CC} ${CFLAGS} -o $@ ${DR-OBJS} ${LIBS}

namegen: namegen.o name_generator.o diceroll.o logos.o ascii_nums.o
	${CC} ${CFLAGS} -o $@ namegen.o name_generator.o diceroll.o logos.o ascii_nums.o ${LIBS}

clean:
	rm *.o tui rolldice namegen

.cpp.o:
	${CC} ${CFLAGS} ${INCLUDES}-c $<
