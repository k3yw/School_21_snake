rm out.o &>/dev/null
gcc -Wall -Werror -Wextra -lncurses -lpthread -o out.o $1 collision.c render.c input.c engine.c ball.c score.c
./out.o