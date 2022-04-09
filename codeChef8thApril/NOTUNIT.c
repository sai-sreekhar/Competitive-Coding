#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>

int main()
{
    int noOfTestCases;
    scanf("%d", &noOfTestCases);

    while (noOfTestCases--)
    {
        int A;
        int B;
        scanf("%d %d", &A, &B);

        int i;
        int j;

        if (A == 1)
        {
            i = 2;
        }
        else
        {
            i = A;
        }

        bool pairFound = false;
        
        if ((i % 2 == 0) && (i + 2 <= B))
        {
            j = i + 2;
            pairFound = true;
        }
        else if ((i % 3 == 0) && (i + 3 <= B))
        {
            j = i + 3;
            pairFound = true;
        }
        else if ((i + 1 >= A) && (i + 3 <= B))
        {
            j = i + 3;
            i = i + 1;
            pairFound = true;
        }

        if (pairFound == false)
        {
            printf("-1\n");
        }
        else
        {
            printf("%d %d\n",i,j);
        }
        
    }
    return 0;
}