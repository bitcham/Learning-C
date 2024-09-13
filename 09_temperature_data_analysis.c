#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MONTHS 12
#define YEAR 3

int main()
{
	double year[YEAR][MONTHS] = { { -2.4, 2.7, 9.0, 14.2, 17.1, 22.8, 28.1, 25.9, 22.6, 15.6, 8.2, 0.6 },{ -2.2, -1.1, 7.7, 14.8, 19.1, 23.3, 27.3, 25.7, 22.4, 14.6, 10.0, -2.8 },{ -1.5, 2.3, 9.8, 13.8, 19.5, 23.4, 26.7, 27.2, 23.7, 15.8, 6.8, 3.1 } };

	printf("[Temperature Data]\n");
	printf("Year index : ");

	for (int j = 1; j <= MONTHS; ++j)
		printf("\t%d", j);

	printf("\n");

	for (int j = 0; j < YEAR; ++j)
	{
		printf("Year %d     : ", j);
		for (int i = 0; i < MONTHS; ++i)
			printf("\t%.1f", year[j][i]);
		printf("\n");
	}

	printf("[Yearly average temperatures of 3 years]\n");
	for (int j = 0; j < YEAR; ++j)
	{
		double avg = 0;
		printf("Year %d     : ", j);
		for (int i = 0; i < MONTHS; ++i)
			avg += year[j][i];
		printf("average temperature = %.1f", avg / (double)MONTHS);
		printf("\n");
	}
	


	printf("[Monthly average temperatures for 3 years]\n");

	printf("Year index : ");
	for (int j = 1; j <= MONTHS; ++j)
		printf("\t%d", j);

	printf("\n");

	printf("Avg temps  : ");

	for (int j = 0; j < MONTHS; ++j)
	{
		double avg = 0;
		
		for (int i = 0; i < YEAR; ++i)
			avg += year[i][j];
		
		printf("\t%.1f", avg / (double)YEAR);

	}


	return 0;
}