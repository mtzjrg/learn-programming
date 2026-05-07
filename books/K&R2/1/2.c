#include <stdio.h>

int main(void)
{
	printf("Alert (\\a)\a\n");
	printf("Escape character (\\e)\n");
	printf("Formfeed Page Break (\\f): \f\n");
	printf("Carriage Return (\\r): \r\n");
	printf("Vertical Tab (\\v): \v\n");
	printf("Apostrophe or single quotation mark (\\'): \'\n");
	printf("Question mark (\\?): \?\n");
	printf("Octal number (\\0nnn): '\\173'\n");
	printf("Hexadecimal number (\\xhh...): '\\x7B'\n");
	return 0;
}
