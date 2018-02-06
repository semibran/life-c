all:
	clang src/main.c src/life.c -lSDL2 -lm -o dist/life
