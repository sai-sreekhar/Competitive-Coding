#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>

#define noOfColors 4
#define noOfPrinters 3

int main()
{
    int noOfTestCases;
    int testCase = 0;
    scanf("%d", &noOfTestCases);

    while (noOfTestCases != 0)
    {
        int **totalInkUnits = (int **)(malloc(noOfColors * sizeof(int *)));
        if (totalInkUnits == 0)
        {
            printf("Memory Allocation Failed");
            continue;
        }
        for (int i = 0; i < noOfPrinters; i++)
        {
            totalInkUnits[i] = (int *)(malloc(noOfPrinters * sizeof(int)));
            if (totalInkUnits[i] == NULL)
            {
                printf("Memory Allocation Failed");
                continue;
            }
        }

        for (int i = 0; i < noOfPrinters; i++)
        {
            for (int j = 0; j < noOfColors; j++)
            {
                scanf("%d", &totalInkUnits[i][j]);
            }
        }

        int eachColorUnitsArr[4] = {0};
        for (int i = 0; i < noOfColors; i++)
        {
            int minUnit = 999999;
            for (int j = 0; j < noOfPrinters; j++)
            {
                if (totalInkUnits[j][i] < minUnit)
                {
                    minUnit = totalInkUnits[j][i];
                }
            }
            eachColorUnitsArr[i] = minUnit;
        }

        printf("Case #%d: ", testCase + 1);

        int totalUnitsToFill = 1000000;
        for (int i = 0; i < noOfColors; i++)
        {
            if (totalUnitsToFill == 0)
            {
                eachColorUnitsArr[i] = 0;
            }
            else if (eachColorUnitsArr[i] <= totalUnitsToFill)
            {
                totalUnitsToFill -= eachColorUnitsArr[i];
            }
            else
            {
                eachColorUnitsArr[i] = totalUnitsToFill;
                totalUnitsToFill = 0;
            }
        }

        if (totalUnitsToFill != 0)
        {
            printf("IMPOSSIBLE\n");
        }
        else
        {
            for (int i = 0; i < noOfColors; i++)
            {
                printf("%d ",eachColorUnitsArr[i]);
            } 
            printf("\n");
        }

        testCase ++;
        noOfTestCases--;
    }

    return 0;
}