#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <string.h>


#define WIDTH 25
#define NAME	"Chambit Oh"
#define ADDRESS "Helsinki, Fin"

void print_multiple_chars(char c, int n_stars, bool endl); // (parameterize)parameter -> argument // prototype - compling
void print_centered_str(char str[]);


int main() 
{
	print_multiple_chars('*', WIDTH, true); // argument
	

	print_centered_str(NAME);
	print_centered_str(ADDRESS);
	print_centered_str("Welcome!");

	print_multiple_chars('*', WIDTH, false);

	return 0;
}

void print_multiple_chars(char c, int n_stars, bool endl) // linking
{
	for (int i = 0; i < n_stars; ++i)
		printf("%c", c); //putchar(c)

	if (endl == true)
		printf("\n");
}

void print_centered_str(char str[])
{
	int n_blanks = 0;
	n_blanks = (WIDTH - strlen(str)) / 2;
	print_multiple_chars(' ', n_blanks, false);
	printf("%s\n", str);
}
