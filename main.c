#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <ncurses.h>


typedef struct Node{
	int data;
	struct Node* next;
	struct Node* prev;
}node;

int get_lines(char *buffer);

int main(int argc, char **argv){
	if(argc < 2){
		perror("Sem argumentos suficientes...");
		exit(1);
	}
	FILE *f = fopen(argv[1], "r");
	
	if(f ==NULL){
		perror("Arquivo nao exite...");
		exit(1);
	}

	char buffer[1024] = {0};

	fread(buffer, 1024, 1, f);
	fclose(f);
	//colocar \0 no final do buffer...
	int lines_buffer = get_lines(buffer);

	node *arr[lines_buffer];
	for(int i = 0; i < lines_buffer; ++i){
		int j = 0;
		while(buffer[j] != '\n'){
			faki->data = buffer[j];
		}
	}

	int current = 0;

	initscr();

	
	endwin();
	return 0;
}

int get_lines(char *buffer){
        int x = 0;
        char *p = strchr(buffer, '\n');
        while(p != NULL){
                x++;
                p = strchr(p+1, '\n');
        }
        return x;
}

