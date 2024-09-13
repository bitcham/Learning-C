#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int compute_pow(int base, int exp);

int main()
{
	int base, exp, result;
	while (scanf("%d %d", &base, &exp) == 2) // end - input other than num
	{
		/*result = 1;
		for (int i = 0; i < exp; ++i)
		{
			result *= base;
		}*/

		result = compute_pow(base, exp);

		printf("Result = %d\n", result);
	}

	return 0;
}

int compute_pow(int base, int exp)
{
	int result;
	result = 1;
	for (int i = 0; i < exp; ++i)
	{
		result *= base;
	}
	return result;
}
