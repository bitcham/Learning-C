#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() 
{
	int income, salary, bonus;

	salary = 100;
	bonus = 30;
	income = salary + bonus;
	
	int takehome, tax;
	tax = 20;
	takehome = income - tax;
	
	double seed_money, target_money, annual_interest;
	
	printf("Input seed money : ");
	scanf("%lf", &seed_money);
	
	printf("Input target money : ");
	scanf("%lf", &target_money);
	
	printf("Input annual interest(%%) : ");
	scanf("%lf", &annual_interest);
	
	double fund = seed_money;
	int year_count = 0;
	
	while (fund < target_money)
	{
		fund += fund * annual_interest / 100.0f;
		year_count += 1;
		printf("%f\n", fund);
	}
	
	printf("It takes %d years\n", year_count);
	
	return 0;
}