#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define SLEN 101

struct book
{
	char name[SLEN];
	char author[SLEN];
};

void print_books(const struct book* books, int n);
void write_books(const char* filename, const struct book* books, int n);
struct book* read_books(const char* filename, int* n);
void read_books2(const char* filename, struct book** books_dptr, int* n);

int main()
{
	int temp;
	int n = 3;

	struct book* my_books = (struct book*)malloc(sizeof(struct book) * n);

	if (!my_books) exit(1);

	my_books[0] = (struct book){ "123", "456" };
	my_books[1] = (struct book){ "456", "789" };
	my_books[2] = (struct book){ "789", "123" };

	print_books(my_books, n);

	printf("\nWriting to a file.\n");
	write_books("books.txt", my_books, n);
	free(my_books);
	n = 0;
	printf("Done.\n");

	printf("\nPress any key to read data from a file.\n\n");
	temp = _getch();

	my_books = read_books("books.txt", &n);
	print_books(my_books, n);
	free(my_books);
	n = 0;

	return 0;
}

void print_books(const struct book* books, int n)
{
	for (int i = 0; i < n; ++i)
		printf("Book %d : \"%s\" written by \"%s\".\n", i + 1, books[i].name, books[i].author);
}

void write_books(const char* filename, const struct book* books, int n)
{
	FILE* fw;


	fw = fopen(filename, "w");

	if (fw == NULL)
	{
		fputs("Error opening file!\n", stderr);
		exit(1);
	}
	fprintf(fw, "%d\n", n);

	for (int i = 0; i < n; ++i)
		fprintf(fw, "%s\n%s\n", books[i].name, books[i].author);


	fclose(fw);

}

struct book* read_books(const char* filename, int* n)
{
	FILE* fr;
	
	
	fr = fopen(filename, "r");

	if (fr == NULL) 
	{
		fputs("Error opening file!\n", stderr);
		exit (1);
	}
	int flag;
	flag = fscanf(fr, "%d%*c", n);
	if (flag != 1)
	{
		printf("Reading failed ");
		exit(1);
	}

	struct book* books = (struct book*)calloc(sizeof(struct book), *n);

	if (!books)
	{
		printf("calloc() failed.");
		exit(1);
	}

	for (int i = 0; i < *n; ++i)
	{
		flag = fscanf(fr, "%[^\n]%*c%[^\n]%*c", books[i].name, books[i].author);

		if (flag != 2)
		{
			printf("Reading failed");
			exit(1);
		}
	}


	fclose(fr);
}

void read_books2(const char* filename, struct book** books_dptr, int* n)
{
	FILE* file = fopen(filename, "r");

	if (file == NULL)
	{
		fputs("Error opening file!\n", stderr);
		exit(1);
	}

	int flag;
	flag = fscanf(file, "%d%*c", n);
	if (flag != 1)
	{
		printf("Reading failed ");
		exit(1);
	}
	struct book* books = (struct book*)calloc(sizeof(struct book), *n);

	if (!books)
	{
		printf("calloc() failed.");
		exit(1);
	}

	for (int i = 0; i < *n; ++i)
	{
		flag = fscanf(file, "%[^\n]%*c%[^\n]%*c", books[i].name, books[i].author);

		if (flag != 2)
		{
			printf("Reading failed");
			exit(1);
		}
	}


	fclose(file);

	*books_dptr = books;
}
