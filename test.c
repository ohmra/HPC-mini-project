#include <stdio.h>
#include <stdlib.h>


int number_of_line(FILE *f){
    if(f == NULL)
        return 0;
    double a;
    double b;
    double c;
    int lines = 0;
    for (;;) {
		int k = fscanf(f, "%lg %lg %lg", &a, &b, &c);
		if (k == EOF) {
			if (ferror(f)){
                printf("read error\n");
                exit(1);
            }
			if (feof(f))
				break;
		}
        lines++;
	}
    return lines;
}

void jump_lines(FILE *f, int nb){
    int lines;
    char ch;
    double a;
    double b;
    double c;
    for(lines = 1; lines<nb; lines++){
        fscanf(f, "%lg %lg %lg", &a, &b, &c);
    }
}

int main(int argc, char** argv){
    if(argc < 2){
        printf("Provide filename\n");
        return 0;
    }
    double a;
    double b;
    double c;

    char* filename = argv[1];
    FILE *f = fopen(filename, "r");
    if (f == NULL){
        printf("no\n");
        return 0;
    }
		
    int nb_line = number_of_line(f);
    for(int i = 0; i<5; i++){
        int k = fscanf(f, "%lg %lg %lg", &a, &b, &c);
        printf("%lg %lg %lg\n", a, b, c);
        jump_lines(f, 5);
    }

    printf("ok\n");
    
    return EXIT_SUCCESS;
}
