all: arcfour

arcfour: arcfour.o
	gcc arcfour.o -o arcfour.so -20 -Wall -fPIC -shared -ldl -D_GNU_SOURCE

arcfour.o: arcfour.c
	gcc -c -02 -Wall arcfour.c

clean:
	rm -f *.o *.so
