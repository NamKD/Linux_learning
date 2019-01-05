lib:
	gcc -c -Wall -Werror -fpic libPrac2.c
	gcc -shared -o libPrac2.so libPrac2.o

app:
	gcc -L./ -Wl,-rpath=/usr/bin -Wall -o practice2 practice2.c -lPrac2