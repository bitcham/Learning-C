#define _crt_secure_no_warnings
#include <stdio.h>
#include <stdlib.h> 
#include <math.h> 
#include <string.h> 

unsigned char to_decimal(const char bi[]);


int main() 
{
	printf("binary (string) to decimal conversion\n");

	printf("%d\n", to_decimal("00000110"));
	printf("%d\n", to_decimal("00010110"));

	printf("%d\n", to_decimal("10010100"));

	return 0;
}


//unsigned char to_decimal(const char bi[])
//{
//	unsigned char sum = 0;
//	int j = 0;
//	for (int i = strlen(bi) - 1; i >= 0; --i)
//	{
//		if (bi[j] == '1')
//			sum = sum + (int)pow(2, i) * 1;
//		else if (bi[j] != '0')
//		{
//			printf("wrong character : %c", bi[j]);
//			exit(1);
//		}
//		j++;
//
//	}
//	return sum;
//}

unsigned char to_decimal(const char bi[])
{
	const size_t bits = strlen(bi);
	unsigned char sum = 0;
	for (size_t i = 0; i < bits; ++i)
	{
		if (bi[i] == '1')
			sum = sum + (int)pow(2, bits - 1 - i);
		else if (bi[i] != '0')
		{
			printf("wrong character : %c", bi[i]);
			exit(1);
		}
	}
  return sum;
}