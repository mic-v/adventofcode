#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#include "vector_i.h"

//compare between two values
int comp(const void *a, const void *b) 
{
        return (*(int *)b - *(int*)a);
}

void input_file(vector_i* first_vec, vector_i* sec_vec) 
{
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
                                sscanf(fnum, "%d", &first_num);
                                sscanf(lnum, "%d", &second_num);
                                vector_pushback(first_vec, first_num);
                                vector_pushback(sec_vec, second_num);
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
                }
                fclose(file);
        }
        qsort(first_vec->elements, vector_size(first_vec), sizeof(first_vec->elements[0]), comp);
        qsort(sec_vec->elements, vector_size(sec_vec), sizeof(sec_vec->elements[0]), comp);
}

int main(int argc, char** argv)
{
        vector_i* first_vec = vector_new();
        vector_i* sec_vec = vector_new();
        vector_createvec(first_vec);
        vector_createvec(sec_vec);
        input_file(first_vec, sec_vec);
        for(int i = first_vec->size - 1; i >= 0; i--)
        {
                printf("%d %d ", first_vec->elements[i], sec_vec->elements[i]); 
        }

	return 0;
}
