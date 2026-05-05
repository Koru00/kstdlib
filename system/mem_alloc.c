#include <stddef.h>

#ifdef __linux__
#include <stdlib.h>
#endif
#ifdef win32
#include <stdlib.h>
#endif
#ifdef KOS2
#include "kstdlib.h"
#endif

void* os_alloc(size_t size)
{
	return malloc(size);
}

void* os_calloc(size_t num, size_t size)
{
	return calloc(num, size);
}

void* os_resize_ptr(void* ptr, size_t new_size)
{
	ptr = realloc(ptr, new_size);
	return ptr;
}

void os_free(void* ptr)
{
	free(ptr);
}
