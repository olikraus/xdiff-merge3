#
#  xdiff_merge Makefile
#  (c) 2024 Oliver Kraus
#  https://github.com/olikraus/c-object
#  CC BY-SA 3.0  https://creativecommons.org/licenses/by-sa/3.0/
#
#  targets
#	clean		clear all objects and executables
#	debug		build debug version (default)
#	sanitize	build debug version with gcc sanitize enabled
#	release		build release version
#

debug: CFLAGS = -g -DCO_USE_ZLIB -Wall -I./libxdiff
sanitize: CFLAGS = -g -DCO_USE_ZLIB -Wall -fsanitize=address -I./libxdiff
release: CFLAGS = -O4 -DNDEBUG -DCO_USE_ZLIB -Wall -I./libxdiff
#gprof: CFLAGS = -g -pg -DCO_USE_ZLIB -Wall -I./co

ifeq ($(shell uname -s),Linux)
LDFLAGS = -lm -lz -lpthread
else
LDFLAGS = -Wl,-Bstatic -lm -lz -lpthread
endif

# COSRC = $(shell ls ./co/*.c)
# COOBJ = $(COSRC:.c=.o)
XDIFFSRC = $(shell ls ./libxdiff/*.c)
XDIFFOBJ = $(XDIFFSRC:.c=.o)

debug: all

sanitize: all 

release: all
	
#gprof: all

all: xdiff_test xdiff_merge3
	
#co_test: $(COOBJ) ./test/co_test.o
#	$(CC) $(CFLAGS)  $^ -o $@ $(LDFLAGS)


xdiff_test: $(XDIFFOBJ) ./tools/xdiff_test.o
	$(CC) $(CFLAGS)  $^ -o $@ $(LDFLAGS)

xdiff_merge3: $(XDIFFOBJ) ./tools/xdiff_merge3.o
	$(CC) $(CFLAGS)  $^ -o $@ $(LDFLAGS)


clean:
	-rm $(XDIFFOBJ) ./tools/xdiff_test.o xdiff_test ./tools/xdiff_merge3.o xdiff_merge3
	