
.PHONY : all
all: example debug paranoid


example: main.c errors.c errors.h
	gcc -o example main.c errors.c

debug: main.c errors.c errors.h
	gcc -g -DDEBUG=1 -o example-debug main.c errors.c

paranoid: paranoid.c errors.c errors.h
	gcc -o paranoid paranoid.c errors.c

.PHONY : clean


clean:
	rm -f ./example*
	rm -f paranoid
