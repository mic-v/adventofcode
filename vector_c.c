#include "vector_c.h"
#include <stdlib.h>

static const int DEFAULT_CAPACITY = 4;

typedef struct vector_c {
        char* elements;
        int capacity;
        int size;
} vector_c;

vector_c* vector_new()
{
        return (vector_c*) malloc(sizeof(vector_c));
        
}

void vector_createvec(vector_c* vec)
{
        vec->elements = calloc(DEFAULT_CAPACITY, sizeof(int));
        vec->capacity = DEFAULT_CAPACITY;
        vec->size = 0;
}

void vector_deletevec(vector_c* vec)
{
        free(vec->elements);
        free(vec);
}
