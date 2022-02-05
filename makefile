exec:
	LD_LIBRARY_PATH=/usr/include/lib
	export LD_LIBRARY_PATH
	gcc -Wall -L/usr/include/lib main.c -lasgp2 -o graph