GCC_IGNORE_ERRS=-Wno-override-init
BUILD_FOLDER=../build/
SRC_FOLDER=./src/
all: build

build: main.c
	gcc -Wall -Wextra -Werror -lncurses main.c -o $(BUILD_FOLDER)main.out;	

run: main.c
	gcc -Wall -Wextra -Werror -lncurses main.c -o $(BUILD_FOLDER)main.out;$(BUILD_FOLDER)main.out

test_texture:
	gcc -Wall -Wextra -Werror -o $(BUILD_FOLDER)texturemap.out texturemap.c -lncurses;$(BUILD_FOLDER)texturemap.out