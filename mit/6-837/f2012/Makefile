CFLAGS=-Wall -Wextra -pedantic -ggdb -g3
CFLAGS+=`sdl2-config --cflags`
CFLAGS+=-fsanitize=address
CFLAGS+=-Icommon/

LDFLAGS=`sdl2-config --libs`
LDFLAGS+=-lm -lGL

SRC=common/*.c

all:
	cc -o objviewer $(CFLAGS) 00-objviewer/*.c $(SRC) $(LDFLAGS)
	cc -o curves-and-surfaces $(CFLAGS) 01-curves-and-surfaces/*.c $(SRC) $(LDFLAGS)

clean:
	rm -f objviewer
	rm -f curves-and-surfaces
