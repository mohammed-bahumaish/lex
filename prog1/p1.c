//  Write a C / C++ program to accept a C program and do error detection & correction for the following.
// Check for un-terminated string constant in the input C program. i.e A string constant begins with double quotes and extends for more than one line.
// Intimate the error line numbers and the corrective actions to user.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    FILE *file = fopen("txt.txt", "r");
    if (file == NULL)
    {
        printf("can not be opened");
        exit(1);
    }

    char line[100];
    int lineNo = 0, open = 0, close = 0;

    while (fgets(line, sizeof(line), file) != NULL)
    {
        lineNo++;
        open = close = 0;
        for (int i = 0; i < strlen(line); i++)
        {
            if (line[i] == '"')
            {
                if (open == 1 && close == 0)
                    close = 1;
                else if (open == 0 && close == 0)
                    open = 1;
                else if (open == 1 && close == 1)
                    close = 0;
            }
        }
        if (open == 1 && close == 0)
        {
            printf("Error at line %i", lineNo);
        }
    }
}