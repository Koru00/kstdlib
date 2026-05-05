#include <stdint.h>

#ifdef __linux__
#include <stdlib.h>
#endif
#ifdef win32
#include <stdlib.h>
#endif
#ifdef KOS2
#include "kstdlib.h"
#endif

void* os_alloc(uint32_t size)
{
  return malloc(size);
}
