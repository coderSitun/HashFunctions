build:
	mkdir build

hash: build
	g++ -c src/hash.cpp -I src/ -I src/sha160/ -o build/hash.o

sha160: build
	g++ -c src/sha160/sha160.cpp -I src/ -I src/sha160/ -o build/sha160.o

main: build
	g++ -c test/main.cpp -I src/ -o build/main.o

run: build hash sha160 main
	g++ -o build/run -g build/*.o

direct:
	g++ -g -o build/run src/hash.cpp src/sha160/sha160.cpp test/main.cpp -I src/ -I src/sha160/

clean:
	rm -rf build