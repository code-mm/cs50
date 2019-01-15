CC = clang
CFLAGS = -fsanitize=integer -fsanitize=undefined -ggdb3 -O0 -std=c11 -Wall -Werror -Wextra -Wno-sign-compare -Wshadow
LDLIBS = -lcs50 -lm

.PHONY: all
all: resize

recover: resize.c
	$(CC) $(CFLAGS) -o resize resize.c $(LDLIBS)

.PHONY: clean
clean:
	rm -f resize
