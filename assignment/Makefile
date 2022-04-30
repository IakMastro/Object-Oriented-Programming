# *****************************************************
# Variables to control Makefile operation

CC = g++
CFLAGS = -Wall -g

# ****************************************************
# Targets needed to bring the executable up to date

all: player mpampis loukas game main a.out clean

a.out:
	$(CC) $(CFLAGS) -o a.out main.o game.o player.o mpampis.o loukas.o -lncurses

main:
	$(CC) $(CFLAGS) -c main.cpp

game:
	$(CC) $(CFLAGS) -c src/game.cpp

player:
	$(CC) $(CFLAGS) -c src/player.cpp

mpampis:
	$(CC) $(CFLAGS) -c src/mpampis.cpp

loukas:
	$(CC) $(CFLAGS) -c src/loukas.cpp

clean:
	rm *.o
