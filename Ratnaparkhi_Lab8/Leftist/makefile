all:lab8

lab8: main.o leftistQ.o leftistNode.o leftistHeap.o
	g++ leftistQ.o leftistNode.o leftistHeap.o main.o -o leftist

main.o: main.cpp 
	g++ -c -std=c++11 main.cpp

leftistQ.o: leftistQ.cpp
	g++ -c -g -std=c++11 leftistQ.cpp

leftistNode.o: leftistNode.cpp
	g++ -c -g -std=c++11 leftistNode.cpp

leftistHeap.o: leftistHeap.cpp
	g++ -c -g -std=c++11 leftistHeap.cpp

clean:
	rm *.o