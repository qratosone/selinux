all:main
	./main
main:main.c struct.h struct.c Linktable.c
	clang -o main main.c struct.c Linktable.c
clean:
	rm main
