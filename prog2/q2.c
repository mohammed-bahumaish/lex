// Write a C / C++ program to accept a C program and do error detection & correction for the following.
// Check for un- terminated multi line comment statement in your C program.

#include <stdio.h>
#include <string.h>
int main()
{
	FILE *fp = fopen("MutiComment.cpp", "r");
	int i;
	int lineno = 0;
	char line[100];
	int open = 0, close = 0, openlineno, closelineno;
	if (fp == NULL)
	{
		printf("File cant be opened\n");
		exit(0);
	}
	printf("File opened correctly!\n");
	while (fgets(line, sizeof(line), fp) != NULL)
	{
		lineno++;
		if (open == 1 && close == 0)
			printf("\n%s", line);
		if (strstr(line, "/*") && open == 0)
		{
			open = 1;
			close = 0;
			openlineno = lineno;
			printf("\n%s", line);
		}
		if (strstr(line, "*/") && close == 0 && open == 1)
		{
			closelineno = lineno;
			close = 1;
			open = 0;
			printf("\n Comment is displayed above!\nComment opened in line no %d and closed in line no %d", openlineno, closelineno);
		}
	}
	if (open == 1 && close == 0)
	{
		printf("\n Unterminated comment in begin in line no %d. It Has to be closed", openlineno);
	}

	return 0;
}
