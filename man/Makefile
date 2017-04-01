PREFIX  = /usr/local
MANDIR  = $(PREFIX)/share/man

RONN = ronn

MANPAGES =	adt_binarytree.1 adt_labels.1
ORGANIZATION = PELLOIN Valentin

%.1 : %.1.ronn
	$(RONN) --manual="$@ manual" --organization="$(ORGANIZATION)" $<

all: $(MANPAGES)

clean:
	rm *.1
	rm *.1.html

clear: clean

install: all
	install -m 0644 $(MANPAGES) $(MANDIR)/man1

uninstall: clean
	rm $(addprefix $(MANDIR)/man1/, $(MANPAGES))
