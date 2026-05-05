#include <string/string.h>
#include <stdio/stdio.h>

#include <stdlib.h>

int main(void)
{
	char* src;

	const char* str1 = "Hello ";
	const char* str = "World!";

	src = malloc(sizeof(char)*13);

	strcat(src, str1);
	strcat(src, str);

	println(src);

	return 0;
}
