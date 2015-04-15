all:lab8

lab8: main.o skewNode.o skewHeap.o leftistNode.o leftistHeap.o leftistQ.o skewQ.o
	g++ skewNode.o skewHeap.o leftistNode.o leftistHeap.o leftistQ.o skewQ.o main.o -o lab8

main.o: main.cpp 
	g++ -c -g -std=c++11 main.cpp

leftistQ.o: ./Leftist/leftistQ.cpp
	g++ -c -g -std=c++11 ./Leftist/leftistQ.cpp

skewQ.o: ./Skew/skewQ.cpp
	g++ -c -g -std=c++11 ./Skew/skewQ.cpp

skewNode.o: ./Skew/skewNode.cpp
	g++ -c -g -std=c++11 ./Skew/skewNode.cpp

skewHeap.o: ./Skew/skewHeap.cpp
	g++ -c -g -std=c++11 ./Skew/skewHeap.cpp

leftistNode.o: ./Leftist/leftistNode.cpp
	g++ -c -g -std=c++11 ./Leftist/leftistNode.cpp

leftistHeap.o: ./Leftist/leftistHeap.cpp
	g++ -c -g -std=c++11 ./Leftist/leftistHeap.cpp

clean:
	rm *.o