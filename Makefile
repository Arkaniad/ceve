# the compiler: gcc for C program, define as g++ for C++
CC = gcc

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS = -Wall

all: main

debug: CFLAGS += -DDEBUG -g
debug: main
# the build target executable:
main: main.o planet.o resource.o
	$(CC) $(CFLAGS) -o main main.o planet.o resource.o

planet.o: planet.c planet.h
	$(CC) $(CFLAGS) -c planet.c

resource.o: resource.c resource.h
	$(CC) $(CFLAGS) -c resource.c

clean:
	$(RM) ceve *.o
