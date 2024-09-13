#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>


void UpdateString(char* str, int(*pf)(int));
void ToUpper(char* str);
void ToLower(char* str);
void Transpose(char* str);

int main()
{
	char options[] = { 'u', 'l', 't'};
	int n = sizeof(options) / sizeof(options[0]);

	typedef void(*FUNC_TYPE)(char*);

	FUNC_TYPE operations[] = { ToUpper, ToLower, Transpose };

	printf("Enter a string\n>> ");

	char input[100];

	while (scanf("%[^\n]%*c", input) != 1)
		printf("Please try again.\n>> ");

	while (1)
	{
		char c;

		printf("Choose an option : \nu) to upper\nl) to lower\nt) to transpose\n");

		if (scanf("%c", &c) != 1)
			printf("Please try again.\n>> ");

		bool found = false;
		
		for (int i = 0; i < n; ++i)
		{
			if (c == options[i])
			{
				(*(operations[i]))(input);
				found = true;
				break;
			}
		}	

		//switch (c)
		//{
		//	case 'u' :
		//		ToUpper(input);
		//		found = true;
		//		break;
		//	case 'l':
		//		ToLower(input);
		//		found = true;
		//		break;
		//}

		if (found)
		{
			printf("Updated string: %s\n", input);
			break;
		}
		else
			printf("Wrong input.\n");
	}


	return 0;
}

void ToUpper(char* str)
{
	while (*str)
	{
		*str = toupper(*str);
		str++;
	}
}

void ToLower(char* str)
{
	while (*str)
	{
		*str = tolower(*str);
		str++;
	}
}

void UpdateString(char* str, int(*pf)(int))
{
	while (*str)
	{
		*str = (*pf)(*str);
		str++;
	}
}

void Transpose(char* str)
{
	while (*str)
	{
		if (islower(*str))
			*str = toupper(*str);
		else if (isupper(*str))
			*str = tolower(*str);
		str++;
	}
}