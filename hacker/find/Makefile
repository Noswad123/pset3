#
# Makefile
# CS50
#

all: find generate

find: find.c helpers.c helpers.h sorts.c sorts.h
	clang -ggdb3 -O0 -std=c11 -Wall -Werror -o find find.c helpers.c sorts.c -lcs50 -lm

generate: generate.c
	clang -ggdb3 -O0 -std=c11 -Wall -Werror -o generate generate.c

clean:
	rm -f *.o a.out core find generate
