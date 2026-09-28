GENERATES = prog prog-a prog-so prog_test prog-a_test prog-so_test README liboutput_static.a liboutput.so
TRASH = *.o *~ o.*
CFLAGS = -Wall -fPIC

all: README test prog prog-a prog-so

README: prog
	./$< 2> $@

test: prog prog-a prog-so
	@set -e; export LD_LIBRARY_PATH=.; \
	echo "Testing empty args"; \
	./prog 2> prog_test; \
	./prog-a 2> prog-a_test; \
	./prog-so 2> prog-so_test; \
	if cmp prog_test prog-a_test && cmp prog_test prog-so_test; then \
		echo "Passed"; \
	else \
		echo "Failed"; \
		exit 1; \
	fi;
	@set -e; export LD_LIBRARY_PATH=.; \
	echo "Testing single arg"; \
	./prog argument1 > prog_test; \
	./prog-a argument1 > prog-a_test; \
	./prog-so argument1 > prog-so_test; \
	if cmp prog_test prog-a_test && cmp prog_test prog-so_test; then \
		echo "Passed"; \
	else \
		echo "Failed"; \
		exit 1; \
	fi;
	@set -e; export LD_LIBRARY_PATH=.; \
	echo "Testing 3 args"; \
	./prog argument1 argument2 argument3 > prog_test; \
	./prog-a argument1 argument2 argument3 > prog-a_test; \
	./prog-so argument1 argument2 argument3 > prog-so_test; \
	if cmp prog_test prog-a_test && cmp prog_test prog-so_test; then \
		echo "Passed"; \
	else \
		echo "Failed"; \
		exit 1; \
	fi
	
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
	rm -f $(TRASH) $(GENERATES)