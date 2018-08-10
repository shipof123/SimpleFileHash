src = src/main.cpp
out = bin/SFH

all:
	mkdir bin
	g++ -std=c++17 $(src) -o $(out)