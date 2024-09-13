#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>


# define PERIOD '.'

int main()
{	

	char ch;
	int ch_count = 0, wr_count = 0, l_count = 0;
	bool word_flag = false;
	bool line_flag = false;

	printf("Enter text : \n");

	while ((ch = getchar()) != PERIOD)
	{
		if (!isspace(ch))
		{
			ch_count++;
		}
		
		if (!isspace(ch) && !line_flag)
		{
			l_count++;
			line_flag = true;
		}

		if (ch == '\n')
			line_flag = false;

		if (!isspace(ch) && !word_flag)
		{
			wr_count++;
			word_flag = true;
		}

		if (isspace(ch))
		{
			word_flag = false;
		}

	}

	printf("Characters = %d, Words = %d, Lines = %d \n", ch_count, wr_count, l_count);





	return 0;
}