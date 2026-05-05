#pragma once

#include <stdint.h>

void* os_alloc(uint32_t size);
void* os_alloc_zero(uint32_t size);
void os_resize_ptr(void* ptr, uint32_t new_size);
void free(void* free);
