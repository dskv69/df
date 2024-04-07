compile: src/*.cpp include/*.h
	g++ src/*.cpp -I ./include -o ./build/build -Wall -std=c++20