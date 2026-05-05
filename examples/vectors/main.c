#include <memory/vector.h>
#include <stdio/stdio.h>

int main(void)
{
	Vector_s vector = VectorInit(INT, 2);	
	VectorPushBack(&vector, (void*) 1);
	VectorPushBack(&vector, (void*) 2);
	VectorPushBack(&vector, (void*) 3);
	VectorPushBack(&vector, (void*) 4);
	
	for (size_t i = 0; i < vector.num_elements; i++)
	{
		printf("%d\n", VectorGetElement(&vector, i));
	}
	return 0;
}
