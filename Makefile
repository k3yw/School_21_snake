
all: build

build: main.c
	gcc -Wall -Wextra -Werror main.c -o main.out;./main.out