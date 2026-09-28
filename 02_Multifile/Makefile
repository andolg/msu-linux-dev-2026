GENERATES = prog prog-a prog-so README liboutput_static.a liboutput.so
TRASH = *.o *~ o.*
CFLAGS = -Wall -fPIC

all: README prog prog-a prog-so

README: prog
	./$< 2> $@

prog: prog.o fun.o const.o

prog-a: prog.o liboutput_static.a
	cc -o $@ $^

prog-so: prog.o liboutput.so
	cc -o $@ $^

liboutput.so: fun.o const.o
	cc -shared -o $@ $^

liboutput_static.a: fun.o const.o
	ar rcs $@ $^

fun.o prog.o: outlib.h

clean:
	rm -f $(TRASH)

distclean: clean
	rm -rf $(GENERATES)