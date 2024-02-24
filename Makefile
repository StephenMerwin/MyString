  #author: Stephen Merwin
  #the compiler: gcc for C program, g++ for C++
  CC = g++

  # compiler flags:
  #  -g    adds debugging information to the executable file
  #  -Wall turns on most, but not all, compiler warnings
  CFLAGS = -Wall -g -std=c++11

  # the build target executable:
  TARGET = main

  #function targets
  FILE1 = my_str

.PHONY: clean tar script #these targets are not to compile files

  all: $(FILE1) $(TARGET)

  $(FILE1): $(FILE1).cpp $(FILE1).h
	$(CC) -c $(FILE1).cpp -o $(FILE1).o $(CFLAGS)

  clean:
	rm $(TARGET) *.o

  tar:
	tar cf $(TARGET).tar *.cpp *.h *.scr Makefile

  script:
	script $(TARGET).scr

  $(TARGET): *.cpp
	$(CC) $(CFLAGS) $(TARGET).cpp -o $(TARGET) *.o
