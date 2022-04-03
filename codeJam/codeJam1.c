#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>

char* evenRowPatternGenerator(int cols)
{
    int i;
    char* evenRowPattern = (char *)malloc(2*cols+2);
    if (evenRowPattern == NULL)
    {
        printf("Memory Allocation Failed");
        return NULL;
    }
    
    for (i = 0; i < 2 * cols + 1; i++)
    {
        if (i % 2 == 0)
        {
            evenRowPattern[i] = '+';
        }
        else
        {
            evenRowPattern[i] = '-';
        }
    }
    evenRowPattern[i] = '\0';

    return evenRowPattern;
}

char* oddRowPatternGenerator(int cols)
{
    int i;
    char* oddRowPattern = (char *)malloc(2*cols+2);
    if (oddRowPattern == NULL)
    {
        printf("Memory Allocation Failed");
        return NULL;
    }

    for (i = 0; i < 2 * cols + 1; i++)
    {
        if (i % 2 == 0)
        {
            oddRowPattern[i] = '|';
        }
        else
        {
            oddRowPattern[i] = '.';
        }
    }
    oddRowPattern[i] = '\0';

    return oddRowPattern;
}

char* firstRowPatternGenerator(int cols)
{
    int i;
    char* firstRowPattern = (char *)malloc(2*cols+2);
    if (firstRowPattern == NULL)
    {
        printf("Memory Allocation Failed");
        return NULL;
    }

    for (i = 0; i < 2 * cols + 1; i++)
    {
        if ((i == 0) || (i == 1))
        {
           firstRowPattern[i] = '.' ;
        }
        else if (i % 2 == 0)
        {
            firstRowPattern[i] = '+';
        }
        else
        {
            firstRowPattern[i] = '-';
        }
    }
    firstRowPattern[i] = '\0';

    return firstRowPattern;
}

char* secondRowPatternGenerator(int cols)
{
    int i;
    char* secondRowPattern = (char *)malloc(2*cols+2);
    if (secondRowPattern == NULL)
    {
        printf("Memory Allocation Failed");
        return NULL;
    }

    for (i = 0; i < 2 * cols + 1; i++)
    {
        if ((i == 0) || (i == 1))
        {
            secondRowPattern[i] = '.';
        }
        else if (i % 2 == 0)
        {
            secondRowPattern[i] = '|';
        }
        else
        {
            secondRowPattern[i] = '.';
        }
    }
    secondRowPattern[i] = '\0';

    return secondRowPattern;
}

int main()
{
    int noOfTestCases = 0;
    scanf("%d", &noOfTestCases);
    int testCase = 0;
    while (noOfTestCases != 0)
    {
        int rows;
        int cols;
        scanf("%d %d", &rows, &cols);

        char* evenRowPattern = evenRowPatternGenerator(cols);
        if (evenRowPattern == NULL)
        {
            printf("Memory Allocation Failed");
            continue;
        }
        
        char* oddRowPattern = oddRowPatternGenerator(cols);
        if (oddRowPattern == NULL)
        {
            printf("Memory Allocation Failed");
            continue;
        }

        char* firstRowPattern = firstRowPatternGenerator(cols);
        if (firstRowPattern == NULL)
        {
            printf("Memory Allocation Failed");
            continue;
        }

        char* secondRowPattern = secondRowPatternGenerator(cols);
        if (secondRowPattern == NULL)
        {
            printf("Memory Allocation Failed");
            continue;
        }

        printf("Case #%d:\n",testCase+1);
        testCase++;

        for (int i = 0; i < 2 * rows + 1; i++)
        {
            if (i == 0)
            {
                printf("%s\n",firstRowPattern);
            }
            else if (i == 1)
            {
                printf("%s\n",secondRowPattern);
            }
            else if (i % 2 != 0)
            {
                printf("%s\n",oddRowPattern);
            }
            else
            {
                printf("%s\n",evenRowPattern);
            }
        }

        free(evenRowPattern);
        free(oddRowPattern);
        free(firstRowPattern);
        free(secondRowPattern);

        noOfTestCases--;
    }

    return 0;
}