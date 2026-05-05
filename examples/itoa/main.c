#include <string/string.h>
#include <stdio/stdio.h>

int main(void)
{
	int num = 12345;

	printf("Num: %d\n", num);

	string str = itoa(num);

	int len = strlen(str);
	printf("string len: %d\n", len);

	println(str);
}
