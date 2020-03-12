#include <stdlib.h>
#include <string.h>
#include <iostream>

int what(char s[])
{
	char *p = s;
	return sizeof(p);
}
int main()
{
	char s[] = "a string";
	int x = what(s);
	std::cout << x << std::endl;
	std::cout << sizeof(s) << std::endl;
	return EXIT_SUCCESS;
}