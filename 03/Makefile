PKG=tutor3.out

DESTDIR = bin/

CFLAGS=-std=gnu99 -Wall
$(PKG): main.c # source.c header.h
	gcc $(CFLAGS) main.c -o $(PKG)
clean:
	rm *.o $(PKG) -f
	rm $(PKG) -f
	rm $(DESTDIR) -rf

install: $(PKG)
	install -d $(DESTDIR)
	install $(PKG) $(DESTDIR)
	rm $(PKG) -f
# install -m -755 $(PKG) 


