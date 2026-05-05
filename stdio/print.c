#include "system/terminal.h"

#include <stddef.h>
#include <stdarg.h>
#include <stdint.h>

void print(const char *str)
{
	for (size_t i = 0; str[i] != '\0'; i++)
	{
		putChar(str[i]);
	}
}

void println(const char *str)
{
	for (size_t i = 0; str[i] != '\0'; i++)
	{
		putChar(str[i]);
	}
	putChar('\n');
}

void printf(const char *str, ...)
{
    va_list args;
    va_start(args, str);

    for (size_t i = 0; str[i] != '\0'; i++)
    {
        char character = (uint8_t)str[i];

        switch (character)
        {
        case '\0':
            goto end;
            break;
        case '\n':
            putChar('\n');
            break;
        case '\t':
            putChar('\t');
            break;
        case '%':
        {
            char type = (uint8_t)str[++i];
            switch (type)
            {
            case '%':
                putChar('%');
                break;
            case 'c':
            {
                char c = (char)(va_arg(args, int));
                putChar(c);
                break;
            }
            case 's':
            {
                char *s = va_arg(args, char *);
                if (s) {
                    // Write string directly to avoid recursion
                    for (char *p = s; *p; p++) {
                        putChar(*p);
                    }
                }
                break;
            }
            /*case 'd':
            {
                int d = va_arg(args, int);
                char *num_str = int_to_str(d);
                for (char *p = num_str; *p; p++) {
                    putChar(*p);
                }
                break;
            }*/
            case 'x':
            {
                unsigned int num = va_arg(args, unsigned int);
                // Simple hex conversion
                char hex_str[20];
                char *ptr = hex_str + 19;
                *ptr = '\0';
                ptr--;

                if (num == 0) {
                    *ptr = '0';
                    putChar('0');
                } else {
                    while (num > 0) {
                        int digit = num % 16;
                        *ptr = (digit < 10) ? ('0' + digit) : ('A' + digit - 10);
                        num /= 16;
                        ptr--;
                    }
                    ptr++;
                    while (*ptr) {
                        putChar(*ptr++);
                    }
                }
                break;
            }
            default:
                putChar('%');
                putChar(type);
                break;
            }
            break;
        }
        default:
            putChar(character);
            break;
        }
    }

end:
    va_end(args);
}

