 mkdir build_manual

 g++ -c lib/hello/hello.cpp -I lib/hello -o build_manual/hello.o

 g++ -c src/prog1/main.cpp -I lib/hello -o build_manual/prog1.o
 g++ build_manual/prog1.o build_manual/hello.o -l pthread -o build_manual/prog1

 make
