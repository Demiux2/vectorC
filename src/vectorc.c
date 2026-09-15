#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <assert.h>
#include "vectorc.h"

// Element access functions
int32_t vec_at(Vector* vector, int32_t pos){
    assert(vector != NULL);
    assert(pos < vector->length && pos >= 0);
    return vector->data[pos];
}

int32_t vec_front(Vector* vector){
    assert(vector != NULL);
    assert(vector->length > 0);
    return vector->data[0];
}

int32_t vec_back(Vector* vector){
    assert(vector != NULL);
    assert(vector->length > 0);
    return vector->data[vector->length-1];
}

int32_t* vec_data(Vector* vector){
    assert(vector != NULL);
    return vector->data;
}

// Capacity functions
bool vec_empty(Vector* vector){
    assert(vector != NULL);
    return (vector->length == 0) ? true : false;
}

size_t vec_size(Vector* vector){
    assert(vector != NULL);
    return vector->length;
}

size_t vec_max_size(Vector* vector){
    assert(vector != NULL);
    return SIZE_MAX/sizeof(*vector->data);
}

void vec_reserve(Vector* vector, size_t new_cap){
    assert(vector != NULL);
    if(new_cap < vector->capacity) return;
    else{
        vector->capacity = new_cap;
        vector->data = realloc(vector->data, vector->capacity*sizeof(*vector->data));
    }
    return;
}

size_t vec_capacity(Vector* vector){
    assert(vector != NULL);
    return vector->capacity;
}

void vec_shrink_to_fit(Vector* vector){
    assert(vector != NULL);
    if(vector->length == vector->capacity) return;
    else{
        vector->capacity = vector->length;
        vector->data = realloc(vector->data, vector->capacity*sizeof(*vector->data));
    }
    return;
}

// Modifiers
void vec_clear(Vector* vector){
    assert(vector != NULL);
    vector->length = 0;
    return;
}

void vec_append(Vector* vector, int32_t value){
    assert(vector != NULL);
    if(vector->length >= vector->capacity){
        if(vector->capacity == 0) vector->capacity = 2;
        else vector->capacity *= 2;
    }
    vector->data = realloc(vector->data, vector->capacity*sizeof(*vector->data));
    vector->data[vector->length] = value;
    vector->length++;
    return;
}
void vec_push(Vector* vector, int32_t value){
    vec_append(vector, value);
    return;
}
void vec_pop(Vector* vector){
    assert(vector != NULL);
    assert(vector->length > 0);
    vector->data[vector->length] = 0;
    vector->length--;
    return;
}
void vec_resize(Vector *vector, int32_t value){
    if(vector->length == value) return;
    else if(vector->length > value){
        vector->length = value;
        return;
    }
    else{
        //TODO: optimizar
        for(int i=vector->length; i < value; i++)
            vec_append(vector, value);
    }
    return;
}

void vec_swap(Vector* vec1, Vector* vec2){
    Vector tmp = *vec1;
    *vec1 = *vec2;
    *vec2 = tmp;
}
