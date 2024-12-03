#include <stdlib.h>
#include <stdio.h>

typedef struct vector_i vector_i; 

vector_i* vector_new();
void vector_createvec(vector_i* vec);
void vector_deletevec(vector_i* vec);
void vector_pushback(vector_i* vec, const int element);
size_t vector_size(vector_i* vec);
size_t vector_capacity(vector_i* vec);

void vector_popback(vector_i* vec);
