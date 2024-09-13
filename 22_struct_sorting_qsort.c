#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> 

struct kid
{
	char name[100];
	int height;
};

int compare(const void* first, const void* second);


int main()
{
	struct kid my_friend[] = {
		"Jack Jack", 40, "Geenie", 300, "Aladdin", 170, "Pinoa", 150
	};

	const int n = sizeof(my_friend) / sizeof(struct kid);

	qsort(my_friend, n, sizeof(struct kid), compare);

	for (int i = 0; i < n; i++)
		printf("%s    \t%d\n", my_friend[i].name, my_friend[i].height);

	return 0;
}

int compare(const void* first, const void* second)
{
	if (((struct kid*)first)->height > ((struct kid*)second)->height)
		return 1;
	else if (((struct kid*)first)->height < ((struct kid*)second)->height)
		return -1;
	else
		return 0;
}