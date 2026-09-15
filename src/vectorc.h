#ifndef VECTORC_H
#define VECTORC_H

#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct{
    int32_t *data;
    size_t length;
    size_t capacity;
} Vector;

// Element access functions
int32_t vec_at(Vector* vector, int32_t pos);
int32_t vec_front(Vector* vector);
int32_t vec_back(Vector* vector);
int32_t* vec_data(Vector* vector);
// Capacity functions
bool vec_empty(Vector* vector);
size_t vec_size(Vector* vector);
size_t vec_max_size(Vector* vector);
void vec_reserve(Vector* vector, size_t new_cap);
size_t vec_capacity(Vector* vector);
void vec_shrink_to_fit(Vector* vector);
// Modifiers
void vec_clear(Vector* vector);
/*
void vec_insert(Vector* vector, int32_t pos, int32_t value);
//void insert_range;
//void emplace;
void vec_erase(Vector* vector, int32_t pos);
*/
void vec_push(Vector* vector, int32_t value);
void vec_append(Vector* vector, int32_t value);
//void emplace_back;
//void append_range;
void vec_pop(Vector* vector);
void vec_resize(Vector* vector, int32_t value);
void vec_swap(Vector* vec1, Vector* vec2);

#endif
