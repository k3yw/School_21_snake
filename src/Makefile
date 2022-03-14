GCC_IGNORE_ERRS=-Wno-override-init -Wno-unused-parameter -Wno-unused-variable
BUILD_FOLDER=../build/
SRC_FOLDER=./src/
OBJECTS=renderengine.c texturemap.c textureassets.c darray.c darraycell.c gameassets.c gameobject.c
all: build

build: main.c
	make clear;gcc -Wall -Wextra -Werror $(GCC_IGNORE_ERRS) $(OBJECTS) main.c -o $(BUILD_FOLDER)main.out -lncurses;

clear:
	rm -rf $(BUILD_FOLDER)*;

run: main.c
	make clear;gcc -Wall -Wextra -Werror -lncurses main.c -o $(BUILD_FOLDER)main.out;$(BUILD_FOLDER)main.out

test_texture:
	make clear;gcc -Wall -Wextra -Werror $(GCC_IGNORE_ERRS) -o $(BUILD_FOLDER)texturemap.out $(OBJECTS) -lncurses;$(BUILD_FOLDER)texturemap.out

test_texture2:
	make clear;gcc -Wall -Wextra -Werror $(GCC_IGNORE_ERRS) -o $(BUILD_FOLDER)texturemap.out $(OBJECTS) -lncurses;

test_darray:
	make clear;gcc -Wall -Wextra -Werror $(GCC_IGNORE_ERRS) -o $(BUILD_FOLDER)darray.out darray.c darraycell.c tests/darray_tests.c tests/tests.c -lncurses;$(BUILD_FOLDER)darray.out