all:lab8

lab8: main.o skewQ.o skewNode.o skewHeap.o
	g++ skewQ.o skewNode.o skewHeap.o main.o -o skew

main.o: main.cpp 
	g++ -c -std=c++11 main.cpp

skewQ.o: skewQ.cpp
	g++ -c -g -std=c++11 skewQ.cpp

skewNode.o: skewNode.cpp
	g++ -c -g -std=c++11 skewNode.cpp

skewHeap.o: skewHeap.cpp
	g++ -c -g -std=c++11 skewHeap.cpp

clean:
	rm *.o