compile: src/*.cpp include/df/*.h
	g++ src/*.cpp -I ./include -o ./build/build -Wall -std=c++20

exec:
	./build/build