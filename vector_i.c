#include "vector_i.h"
#include <stdlib.h>

static const int DEFAULT_CAPACITY = 4;

typedef struct vector_i {
        int* elements;
        int capacity;
        int size;
} vector_i;

vector_i* vector_new()
{
        return (vector_i*) malloc(sizeof(vector_i));
        
}

void vector_createvec(vector_i* vec)
{
        vec->elements = calloc(DEFAULT_CAPACITY, sizeof(int));
        vec->capacity = DEFAULT_CAPACITY;
        vec->size = 0;
}

void vector_deletevec(vector_i* vec)
{
        free(vec->elements);
        free(vec);
}

void vector_pushback(vector_i* vec, const int element)
{
        // if vec size and vec capacity is at full 
        if(vec->size > 0 && vec->size % vec->capacity == 0)
        {
                vec->capacity = (vec->capacity / DEFAULT_CAPACITY + 1) * DEFAULT_CAPACITY;
                vec->elements = realloc(vec->elements, vec->capacity * sizeof(int));
                printf("New allocation %d\n", vec->capacity);
        }
        vec->elements[vec->size++] = element;

}

size_t vector_size(vector_i* vec)
{
        return vec->size;
}

size_t vector_capacity(vector_i* vec)
{
        return vec->capacity;
}

void vector_popback(vector_i* vec)
{
        int lastIndex = vec->size - 1;
        vec->elements[vec->size] = 0;
        vec->size--;
}
