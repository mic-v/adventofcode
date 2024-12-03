#include <stdio.h>
#include "vector_i.h"
#include <memory.h>

int comp(const void *a, const void *b) 
{
        return (*(int *)b - *(int*)a);
}

void input_file() 
{
        vector_i* first_vec = vector_new();
        vector_createvec(first_vec);
        int c;
        FILE *file;
        file = fopen("input.txt", "r");
        if(file) 
        {
                size_t size = 6;
                char fnum[size];
                char lnum[size];
                memset(fnum, '\0', sizeof(fnum));
                memset(lnum, '\0', sizeof(lnum));
                int i = 0;
                int j = 0;
                int first_num = 0;
                int second_num = 0;
                while((c = getc(file)) != EOF) {
                        if(i== size - 1 && j == size - 1) {
                                //set end of string
                                //fnum[first_num] = '\0';
                                //lnum[second_num] = '\0';
                                sscanf(fnum, "%d", &first_num);
                                sscanf(fnum, "%d", &second_num);
                                //printf("First num: %d Second num: %d\n", first_num, second_num);
                                vector_pushback(first_vec, first_num);
                                //reset string
                                i = 0;
                                j = 0;
                                fnum[0] = '\0';
                                lnum[0] = '\0';
                        }
                        else if(c != ' ')
                        {
                               if(i < size - 1){
                                       fnum[i++] = c;
                               }
                               else if(j < size - 1){
                                       lnum[j++] = c;
                               }
                        }
                        //putchar(c);
                }
                fclose(file);
        }
        for(int i = 0; i < vector_size(first_vec); i++)
        {
                printf("%d\n", first_vec->elements[i]);
        }
}

int main(int argc, char** argv)
{
        printf("testing\n");
        input_file();
	return 0;
}
