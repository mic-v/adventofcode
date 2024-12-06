#include <stdlib.h>
#include <stdio.h>

typedef struct vector_c vector_c; 

vector_c* vector_new();
void vector_createvec(vector_c* vec);
void vector_deletevec(vector_c* vec);
