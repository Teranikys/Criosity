//
// Created by Teranikys on 8/17/2024.
//

#include "value.h"

#include <stdio.h>

#include "memory.h"

void initValueArray(ValueArray *array) {
    array->count = 0;
    array->capacity = 0;
    array->values = NULL;
}

void freeValueArray(ValueArray *array) {
    FREE_ARRAY(Value, array->values, array->capacity);
    initValueArray(array);
}

void printValue(const Value value) {
    printf("%g", value);
}

void writeValueArray(ValueArray *array, const Value value) {
    if (array->count == array->capacity) {
        const int oldCapacity = array->capacity;
        array->capacity = GROW_CAPACITY(array->capacity);
        array->values = GROW_ARRAY(
            Value,
            array->values,
            oldCapacity,
            array->capacity);
    }

    array->values[array->count++] = value;
}
