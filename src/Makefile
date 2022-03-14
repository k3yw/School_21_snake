GCC_IGNORE_ERRS=-Wno-override-init -Wno-unused-parameter
BUILD_FOLDER=../build/
SRC_FOLDER=./src/
OBJECTS=gameengine.c renderengine.c texturemap.c
all: build

build: main.c
	make clear;gcc -Wall -Wextra -Werror -lncurses main.c -o $(BUILD_FOLDER)main.out;

clear:
	cd $(BUILD_FOLDER);rm -rf *;

run: main.c
	make clear;gcc -Wall -Wextra -Werror -lncurses main.c -o $(BUILD_FOLDER)main.out;$(BUILD_FOLDER)main.out

test_texture:
	make clear;gcc -Wall -Wextra -Werror $(GCC_IGNORE_ERRS) -o $(BUILD_FOLDER)texturemap.out $(OBJECTS) -lncurses;$(BUILD_FOLDER)texturemap.out

test_texture2:
	make clear;gcc -Wall -Wextra -Werror $(GCC_IGNORE_ERRS) -o $(BUILD_FOLDER)texturemap.out $(OBJECTS) -lncurses;