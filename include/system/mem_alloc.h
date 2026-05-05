#pragma once

#include <stddef.h>

void* os_alloc(size_t size);
void* os_calloc(size_t num, size_t size);
void* os_resize_ptr(void* ptr, size_t new_size);
void os_free(void* ptr);
