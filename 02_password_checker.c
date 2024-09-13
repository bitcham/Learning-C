#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int password = 123;
	int user_input = 0;

	/*
	printf("Enter the password : ");
	scanf("%d", &user_input);

	while (user_input != password)
	{
		printf("Enter the password : ");
		scanf("%d", &user_input);
	}*/

	do
	{
		printf("Enter the password : ");
		scanf("%d", &user_input);
	} while (user_input != password);

	printf("Good!");

	return 0;
}