PKG=tutor8.out

DESTDIR = bin/

CFLAGS=-std=gnu99 -g -Wall
$(PKG): main.c queue.c queue.h
	gcc $(CFLAGS) main.c queue.c -o $(PKG)
clean:
	rm *.o $(PKG) -f
	rm $(PKG) -f
	rm $(DESTDIR) -rf

install: $(PKG)
	install -d $(DESTDIR)
	install $(PKG) $(DESTDIR)
	rm $(PKG) -f
# install -m -755 $(PKG) 


