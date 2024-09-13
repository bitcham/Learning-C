#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void swap(char** xp, char** yp);
void printStringArray(char* arr[], int size);
void selectionSort(char* arr[], int n);


int main()
{
	//int arr[] = { 64, 25, 12, 22, 11 };
	//int n = sizeof(arr) / sizeof(arr[0]);

	//selectionSort(arr, n); // ascending order
	//
	//printArray(arr, n);

	char* arr[] = { "Cherry", "AppleBee", "Pineapple", "Apple", "Orange" };
	// array of pointers of str array
	int n = sizeof(arr) / sizeof(arr[0]);

	printStringArray(arr, n);

	selectionSort(arr, n); // ascending order
	
	printStringArray(arr, n);


	return 0;
}

void swap(char** xp, char** yp)
{
	char* temp = *xp;
	*xp = *yp;
	*yp = temp;
}
void printStringArray(char* arr[], int size)
{
	for (int i = 0; i < size; ++i)
		puts(arr[i]);
	printf("\n");

}
void selectionSort(char* arr[], int n)
{
	int i, j, min_idx;

	// One by one move boundary of unsorted subarray
	for (i = 0; i < n - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < n; j++)
		{
			if (strcmp(arr[min_idx], arr[j]) > 0)
				min_idx = j;
		}

		swap(&arr[min_idx], &arr[i]);
	}

}