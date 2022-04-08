# Makefile for Writing Make Files Example

# *****************************************************
# Variables to control Makefile operation

CC = g++
CFLAGS = -Wall -g

# ****************************************************
# Targets needed to bring the executable up to date

all: course student main a.out clean

a.out:
	$(CC) $(CFLAGS) -o a.out main.o course.o student.o

main:
	$(CC) $(CFLAGS) -c main.cpp

student:
	$(CC) $(CFLAGS) -c src/student.cpp

course:
	$(CC) $(CFLAGS) -c src/course.cpp

clean:
	rm *.o