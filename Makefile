a01.out: main01.o a01.o matrix01.o
	gcc -o a01.out -Wall -g main01.o a01.o matrix01.o
matrix01.o: matrix.c
	gcc -g -c matrix.c -o matrix01.o
main01.o: main01.c 
	gcc -g -c -Wall main01.c -o main01.o
a01.o: a01.c
	gcc -o a01.o -Wall -g -c a01.c 
	
	
	
a02.out: main02.o a02.o matrix02.o
	gcc -o a02.out -Wall -g main02.o a02.o matrix02.o
matrix02.o: matrix.c
	gcc -g -c matrix.c -o matrix02.o
main02.o: main02.c 
	gcc -g -c -Wall main02.c -o main02.o
a02.o: a02.c
	gcc -o a02.o -Wall -g -c a02.c 

a03.out: main03.o a03.o matrix03.o
	gcc -o a03.out -Wall -g main03.o a03.o matrix03.o
matrix03.o: matrix.c
	gcc -g -c matrix.c -o matrix03.o
main03.o: main03.c 
	gcc -g -c -Wall main03.c -o main03.o
a03.o: a03.c
	gcc -o a03.o -Wall -g -c a03.c 

a04.out: main04.o a04.o matrix04.o
	gcc -o a04.out -Wall  -O3 main04.o a04.o matrix04.o
matrix04.o: matrix.c
	gcc  -c -O3 matrix.c -o matrix04.o
main04.o: main04.c
	gcc  -c -O3 -Wall main04.c -o main04.o
a04.o: a04.c
	gcc -o a04.o -Wall -O3 -c  a04.c

a05.out: main05.o a05.o matrix05.o
	gcc -o a05.out -Wall -g main05.o a05.o matrix05.o
matrix05.o: matrix.c
	gcc -g -c matrix.c -o matrix05.o
main05.o: main05.c
	gcc -g -c -Wall main05.c -o main05.o
a05.o: a05.c
	gcc -o a05.o -Wall -g -c a05.c

a06.out: main06.o a06.o matrix06.o
	gcc -o a06.out -Wall -g main06.o a06.o matrix06.o
matrix06.o: matrix.c
	gcc -g -c matrix.c -o matrix06.o
main06.o: main06.c
	gcc -g -c -Wall main06.c -o main06.o
a06.o: a06.c
	gcc -o a06.o -Wall -g -c a06.c

a07.out: main07.o a07.o matrix07.o
	gcc -o a07.out -Wall -g main07.o a07.o matrix07.o
matrix07.o: matrix.c
	gcc -g -c matrix.c -o matrix07.o
main07.o: main07.c
	gcc -g -c -Wall main07.c -o main07.o
a07.o: a07.c
	gcc -o a07.o -Wall -g -c a07.c
	
a08.out: main08.o a08.o matrix08.o
	gcc -o a08.out -Wall -g main08.o a08.o matrix08.o
matrix08.o: matrix.c
	gcc -g -c matrix.c -o matrix08.o
main08.o: main08.c
	gcc -g -c -Wall main08.c -o main08.o
a08.o: a08.c
	gcc -o a08.o -Wall -g -c a08.c
