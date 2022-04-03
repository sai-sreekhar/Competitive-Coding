#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}
int main()
{
    int noOfTestCases = 0;
    int testCase = 1;
    scanf("%d",&noOfTestCases);
    
    while (testCase <= noOfTestCases)
    {
        int noOfDice;
        scanf("%d",&noOfDice);

        int sidesOfDiceArr[noOfDice];

        for (int i = 0; i < noOfDice; i++)
        {
            scanf("%d",&sidesOfDiceArr[i]);
        }
        
        qsort(sidesOfDiceArr, noOfDice, sizeof(int), cmpfunc);

        int result = 1;
        for (int i = 0; i < noOfDice; i++)
        {
            if (sidesOfDiceArr[i] >= result)
            {
                result++;
            }
        }

        printf("Case #%d: %d\n",testCase,result-1);
        
        testCase++;
    }
    
    return 0;
}