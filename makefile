run : main
	./main
main : matrix.o main.o
	gcc matrix.o main.o -o main
matrix.o : matrix.c
	gcc -c matrix.c -o matrix.o
main.o : main.c
	gcc -c main.c -o main.o
clean :
	rm -rf main.o matrix.o main