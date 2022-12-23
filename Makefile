SRC=$(wildcard *.cpp)

all:
	g++ $(SRC) -o build 

run:
	./build
