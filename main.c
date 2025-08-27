#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

int main(int argc, char **argv){
	if(argc < 2){
		perror("Sem argumentos suficientes...");
		exit(1);
	}
	FILE *f = fopen(argv[1], "r");

	char buffer[1024] = {0};

	fread(buffer, 1024, 1, f);
	fclose(f);

	int current = 0;

	initscr();

	printw("%s", buffer);
	getch();
	
	endwin();
	return 0;
}
