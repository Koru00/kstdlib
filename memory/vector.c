#include "memory/vector.h"
#include "system/mem_alloc.h"

int GetTypeSize(VectorType_e type);

// Init a vector and resize it to start_size * element_size
// start_size is the max num of element a the creation of the vector
Vector_s VectorInit(VectorType_e type, size_t start_size)
{
	Vector_s vector = { 0 };
	vector.type = type;
	vector.max_num_elements = start_size;
	vector.num_elements = 0;
	// TODO Implement allocation for the current type
	vector.int_ptr = os_alloc(GetTypeSize(type) * start_size);
	return vector;	
}

// Resize the vector to a new size
void VectorResize(Vector_s* vector, size_t new_size)
{
	switch (vector->type)
	{
		case INT:
		os_resize_ptr(vector->int_ptr, GetTypeSize(vector->type) * new_size);
		// If the resize was suceful
		if (vector->int_ptr)
		{
			vector->max_num_elements = new_size;
		}
		break;
		// TODO Implement other types
		deafult:
		// TODO Trow error unknow type
		break;
	}
}

// Push back a new element to the end of the vector
// If the vector is to small it is resized automaticaly
void VectorPushBack(Vector_s* vector, const void* element)
{
	if (vector->num_elements >= vector->max_num_elements)
	{
		// Double the size of the vector
		VectorResize(vector, vector->max_num_elements * 2);
	}
	
	switch (vector->type)
	{
		case INT:
		if (vector->int_ptr)
		{
			vector->int_ptr[vector->num_elements++] = (int) element;
		}
		break;
		// TODO Implement other types
		deafult:
		// TODO Trow error unknow type
		break;
	}		
}

void* VectorGetElement(Vector_s* vector, size_t index)
{
	// Check if index is out of bound
	// TODO If outbound exit with error
	if (index < 0 || index >= vector->num_elements)
		return;
	
	// TODO make check what type is the vector
	return (void*) vector->int_ptr[index];
}

int GetTypeSize(VectorType_e type)
{
	switch (type)
	{
		case INT:
		return sizeof(int);
		break;
		case FLOAT:
		return sizeof(float);
		break;
		case DOUBLE:
		return sizeof(double);
		break;
		case CHAR:
		return sizeof(char);
		break;
		// If unknow type just return 1
		deafult:
		return 1;
		break;
	}
}
