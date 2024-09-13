#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define NLEN 30

struct name_count {
	char first[NLEN];
	char last[NLEN];
	int num;
};

void receive_input(struct name_count*);
void count_characters(struct name_count*);
void show_result(const struct name_count*);
char* s_gets(char* st, int n);

int main()
{
	struct name_count user_name;

	receive_input(&user_name);
	count_characters(&user_name);
	show_result(&user_name);

	return 0;
}

char* s_gets(char* st, int n)
{
	char* ret_val;
	char* find;

	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		find = strchr(st, '\n');
		if (find)
			*find = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
}

void receive_input(struct name_count* name)
{

	printf("Input your first name : \n>>");
	s_gets(name->first, NLEN); // scanf("[^\n]%*c", name->first); 줄바꿈이 나타날때까지 c하라를 무시해라(줄바꿈)
	if (name->first == NULL)
		printf("Wrong input");
	

	printf("Input your last name : \n>>");
	s_gets(name->last, NLEN);
	if (name->last == NULL)
		printf("Wrong input");
	
}

void count_characters(struct name_count* name)
{
	name->num = strlen(name->first) + strlen(name->last);
}

void show_result(const struct name_count* name)
{
	printf("Hi, %s %s.\n Your name has %d characters.\n",
		name->first, name->last, name->num);
}