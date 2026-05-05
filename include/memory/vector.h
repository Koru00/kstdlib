#pragma once

#include <stddef.h>

// TODO implement a TypeDescriptor

typedef enum VectorType_e {
	INT,
	FLOAT,
	DOUBLE,
	CHAR
} VectorType_e;

typedef struct Vector_s {
	size_t max_num_elements;
	size_t num_elements;
	VectorType_e type;
	union {
		int* int_ptr;
		float* float_ptr;
		double* double_ptr;
		char* char_ptr;
	};
} Vector_s;

// Init a vector and resize it to start_size * element_size
// start_size is the max num of element a the creation of the vector
Vector_s VectorInit(VectorType_e type, size_t start_size);

// Resize the vector to a new size
void VectorResize(Vector_s* vector, size_t new_size);

// Push back a new element to the end of the vector
// If the vector is to small it is resized automaticaly
void VectorPushBack(Vector_s* vector, const void* element);

void* VectorGetElement(Vector_s* vector, size_t index);
