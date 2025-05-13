all: a2_q1_lib.o a2_q1.o a2_q1 a2_q2_lib.o a2_q2.o a2_q2

a2_q1_lib.o: src/a2_q1_lib.c
	gcc -Wall -I. -c -o a2_q1_lib.o src/a2_q1_lib.c

a2_q1.o: src/a2_q1.c src/a2_q1.h
	gcc -Wall -I. -c -o a2_q1.o src/a2_q1.c

a2_q1: a2_q1_lib.o a2_q1.o
	gcc -g -Wall -o a2_q1 a2_q1.o a2_q1_lib.o

a2_q2_lib.o: src/a2_q2_lib.c
	gcc -Wall -I. -c -o a2_q2_lib.o src/a2_q2_lib.c

a2_q2.o: src/a2_q2.c
	gcc -Wall -I. -c -o a2_q2.o src/a2_q2.c

a2_q2: a2_q2_lib.o a2_q2.o a2_q1_lib.o
	gcc -g -Wall -o a2_q2 a2_q2.o a2_q2_lib.o a2_q1_lib.o

clean:
	del -f *.o a2_q1 a2_q2
