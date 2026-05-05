#include <string/string.h>
#include <stdio/stdio.h>

int main(void)
{
	int num = 12345;

	printf("Num: %d\n", num);

	string str = itoa(num);

	println(str);
}
