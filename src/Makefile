DUNDTOOLS-OBJS = dundtools.o name_generator.o diceroll.o ascii_nums.o character_creator.o logos.o stats.o export.o equipment.o
DR-OBJS = rolldice.o diceroll.o logos.o ascii_nums.o
NAMEGEN-OBJS = namegen.o name_generator.o diceroll.o logos.o ascii_nums.o
CFLAGS = -Wall -g
CC = g++
INCLUDE = -I../include -I/usr/local/include
LIBS = -lncurses -lOpenXLSX

all: dundtools rolldice namegen

dundtools: ${DUNDTOOLS-OBJS}
	${CC} ${CFLAGS} ${INCLUDE} -o ../bin/$@ ${DUNDTOOLS-OBJS} ${LIBS}

rolldice: ${DR-OBJS}
	${CC} ${CFLAGS} -o ../bin/$@ ${DR-OBJS} ${LIBS}

namegen: ${NAMEGEN-OBJS}
	${CC} ${CFLAGS} -o ../bin/$@ ${NAMEGEN-OBJS} ${LIBS}

clean:
	rm *.o ../bin/*

.cpp.o:
	${CC} ${CFLAGS} ${INCLUDES}-c $<
