hash:
	g++ -c src/hash.cpp -I src/ -o build/hash.o

sha160:
	g++ -c src/sha160/sha160.cpp -I src/ -I src/sha160/ -o build/sha160.o

main:
	g++ -c test/main.cpp -I src/ -o build/main.o

clean:
	rm build/*