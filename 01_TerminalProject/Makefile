DESTDIR ?= $(HOME)/tmp/01_TerminalProject
BINDIR ?= /usr/bin

Show: Show.c
	cc Show.c -o $@ -lncursesw

install: Show
	install -D -m 755 Show "$(DESTDIR)$(BINDIR)/Show"

.PHONY: clean install
clean:
	rm -f *~ *.o Show a.out