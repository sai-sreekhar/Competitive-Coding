#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>

int main()
{
    int noOfTestCases;
    scanf("%d",&noOfTestCases);

    while (noOfTestCases--)
    {
        int rentPerMonth;
        int costOfCooler;

        scanf("%d",&rentPerMonth);
        scanf("%d",&costOfCooler);

        if (costOfCooler % rentPerMonth == 0)
        {
            printf("%d\n",costOfCooler/rentPerMonth-1);
        }
        else
        {
            printf("%d\n",costOfCooler/rentPerMonth);
        }
    }
    
    return 0;
}