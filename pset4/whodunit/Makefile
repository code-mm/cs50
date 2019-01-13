CC = clang
CFLAGS = -fsanitize=integer -fsanitize=undefined -ggdb3 -O0 -std=c11 -Wall -Werror -Wextra -Wno-sign-compare -Wshadow
LDLIBS = -lcs50 -lm

.PHONY: all
all: whodunit

whodunit: whodunit.c
	$(CC) $(CFLAGS) -o whodunit whodunit.c $(LDLIBS)

.PHONY: clean
clean:
	rm -f whodunit verdict.bmp
