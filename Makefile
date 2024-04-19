main: HW2.o list.o
	gcc -o HW2 HW2.o list.o

HW2.o: HW2.c list.h
	gcc -c HW2.c

list.o: list.c
	gcc -c list.c

clean:
	rm HW2 HW2.o list.o
