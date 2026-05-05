#include "string/string.h"
#include "math/math.h"
#include "system/mem_alloc.h"

string itoa(int num)
{	
	// if the num is 0 just return "0"
	if (num == 0)
		return "0";

	int num_digits = digits(num);

	// Allocate the size of the number + '\0'
	string str = (char*) os_alloc(sizeof(char)*num_digits + 1);

	for (int i = 0; num != 0; i++)
	{
		// get the digit and add 48 to convert it in ascii
		char c = (char)((num % 10) + 48);

		// add c to the string	
		str[num_digits - i - 1] = c;

		// divide num by 10
		num /= 10;
	}

	// Add the null terminator to the end of the string
	str[num_digits+1] = '\0';

	// return the string
	return str;
}
