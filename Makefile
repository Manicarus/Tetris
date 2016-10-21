SHELL = /bin/sh

CPP = g++
HDIR = ./include
SDIR = ./source
EXEC = Tetris
#OBJECTS =
TESTBENCH = console
TBDIR = ./lab

all:

test:
	$(CPP) -g $(TBDIR)/tb_$(TESTBENCH).cpp $(SDIR)/$(TESTBENCH).cpp

clean:
