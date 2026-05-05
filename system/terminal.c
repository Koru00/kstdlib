#include "system/terminal.h"

// if on linux or windows use the standard putChar
#ifdef __linux__
#include <stdio.h>
#endif
#ifdef _WIN32
#include <stdio.h>
#endif
// if on a custom OS us the OS lib for putChar
#ifdef KOS
// include lib for putChar
#endif


void putChar(char c)
{
	putchar(c);
}
