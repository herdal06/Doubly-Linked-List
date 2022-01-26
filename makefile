hepsi: derle calistir

derle:
	g++ -I ./include/ -o ./lib/Sayi.o -c ./src/Sayi.cpp
	g++ -I ./include/ -o ./lib/Node.o -c ./src/Node.cpp
	g++ -I ./include/ -o ./lib/Doublylinkedlist.o -c ./src/Doublylinkedlist.cpp
	g++ -I ./include/ -o ./lib/Islem.o -c ./src/Islem.cpp
	g++ -I ./include/ -o ./bin/test ./lib/Sayi.o ./lib/Node.o ./lib/Doublylinkedlist.o ./lib/Islem.o ./src/Test.cpp

calistir:
	./bin/test