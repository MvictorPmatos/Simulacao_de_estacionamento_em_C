.cpp.o:	$*.h
	g++	-Wall -c $*.cpp

all:	parking

parking:	parking.o lines.o simple.o valet.o
	g++ -o $@ $^


clean:
	rm *.o parking 