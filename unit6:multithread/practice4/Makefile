clean:
	rm -rf ./wrapper.o
	rm -rf ./libwrapper.so
	rm -rf ./prac4
	rm -rf ./namkd.txt

build:
	gcc -L./ -Wl,-rpath=/usr/bin -Wall -o prac4 prac4.c -lpthread -lwrapper

lib:
	gcc -c -Wall -Werror -fpic wrapper.c
	gcc -shared -o libwrapper.so wrapper.o
	cp ./libwrapper.so /usr/bin

all: clean lib build