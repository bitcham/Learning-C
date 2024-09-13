#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

double avg_cal(double *, int n);

int main()
{
	double arr1[5] = { 10, 13, 12, 7, 8 };
	double arr2[5] = { 1.8, -0.2, 6.3, 13.9, 20.5 };
	double arr3[3] = { 1, 2, 3 };// different size
 
	printf("address = %p\n", arr1);
	printf("size = %zd\n", sizeof(arr1));
	printf("avg = %.2f\n", avg_cal(arr1, sizeof(arr1)/sizeof(arr1[0])));
	printf("avg = %.2f\n", avg_cal(arr2, sizeof(arr2) / sizeof(arr2[0])));
	printf("avg = %.2f\n", avg_cal(arr3, sizeof(arr3) / sizeof(arr3[0])));

	return 0;
}


double avg_cal(double* data_array, int n)
{
	double avg = 0.0;
	//for (int i = 0; i < sizeof(data_array)/sizeof(data_array[0]); ++i) // recognize pointer size
	for (int i = 0; i < n; ++i)
	{
		avg += data_array[i];
	}
	avg /= (double)n;

	return avg;
}