src = src/main.cpp
out = bin/SFH

all:
	g++ -std=c++17 $(src) -o $(out)
