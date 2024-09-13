#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define num_limit 1024

void ToUpper(char*);
int punctcount(const char*);

int main()
{
	char line[num_limit];
	char* new_line = NULL;
	fgets(line, num_limit, stdin);
	new_line = strchr(line, '\n'); //find first newline
	if (new_line)
		* new_line = '\0';

	ToUpper(line);
	puts(line);
	printf("%d\n", punctcount(line));

	return 0;
}

void ToUpper(char* str)
{
	while (*str)
	{
		*str = toupper(*str);
		/*if (islower(*str)
			* str = toupper(*str);*/
		str++;
	}
}
int punctcount(const char* str)
{
	int ct = 0;
	while (*str)
	{
		if (ispunct(*str))
			ct++;
		str++;
	}
	return ct;
}