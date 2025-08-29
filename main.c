#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>

typedef struct Node{
	int data;
	struct Node* next;
	struct Node* prev;
}node;

static char* read_file_all(const char *path size_t *out_len){
	FILE *f = fopen(path, "rb")
	if (!f){
		perror("Erro ao abrir o arquivo");
		exit(1);
		return NULL; 
	}
	if (fseek(f, 0, SEEK_END) != 0){
		perror("fseek");
		fclose(f);
		exit(1); 
	}
	long sz = ftell(f)
	if (sz < 0){
		perror("ftell");
		fclose(f);
		exit(1); 
	}
	rewind(f)

	char *buf = (char*)malloc((size_t)sz + 1);
	if(!buf){
		perror(malloc);
		fclose(f);
		exit(1);
	}

	size_t n= fread(f, 1, (size_t)sz, f)
	buf[n] = '\0';
	fclose(f);

	if (out_len) *out_len = n;
	return buf;

}

static int count_lines_buf(const char *buffer, size_t n) {
	if (n == 0) return 0;
	int lines = 0;
	for (size_t i = 0; i < n; ++i){
		if (buffer[i] == '\n') lines++;
	}
	if (n > 0 && buffer[n-1] != '\n') lines ++;
	return lines;
}

static Node* make_node(int ch){
	Node *p = (Node*)malloc(sizeof(Node));
	if (!p){
		perror("malloc node");
	exit(1);
	}
	p->data = ch;
	p->next = NULL;
	p->prev = NULL;
	return p;
}
int main(int argc, char **argv){
	if(argc < 2){
		fprintf(stderr, "Uso: %s <rquivo>\n", argv[0]);
		return 1;
	}

	size_t nbytes = 0;
	char *buffer = read_file_all(argv[1], &nbytes);

	int total_lines = count_lines_buf(buffer, nbytes);
	Node **arr = NULL;

	if (total_lines > 0){
		arr = (Node**)calloc((size_t)total_lines, sizeof(Node*));
		if (!arr){
			perror("calloc arr");
			free(buffer);
			return 1;
		}
	}

	int total_lines = count_lines_buf(buffer, nbytes);
	Node **arr = NULL;
	if (total_lines > 0){
		arr = (Node**)calloc((size_t)total_lines, sizeof(Node*));
		if (!arr){
			perror("calloc arr")
			free(buffer);
			return 1;
		}
	}

	int line_idx = 0;
	Node *head = NULL, *tail = NULL;

	for (size_t i = 0; i < nbytes; ++i){
		unsigned char c = (unsigned char)buffer[i];

		if (c == '\r')
	}
}
