all: link

install : link
	cp cmmk ~/bin/cmmk

compile :
	gcc -c main.c

link : compile
	gcc main.o -lhidapi-hidraw -lusb-1.0 -lcmmk -lm -o cmmk

clean:
	rm -f cmmk
	rm -f *.o
	rm -f *~
