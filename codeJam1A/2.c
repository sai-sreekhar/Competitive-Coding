#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>

int main()
{
    int noOftestCases;
    scanf("%d",&noOftestCases);
    
    int testCaseId = 1;
    
    while (testCaseId <= noOftestCases)
    {
        int noOfExercises;
        int noOfWeights;
        scanf("%d %d",&noOfExercises,&noOfWeights);

        int weightsArr[noOfExercises][noOfWeights];

        for (int i = 0; i < noOfExercises; i++)
        {
            for (int j = 0; j < noOfWeights; j++)
            {
                scanf("%d",&weightsArr[i][j]);
            }
        }
        
        int operations = 0;

        for (int i = 0; i < noOfExercises; i++)
        {
            for (int j = 0; j < noOfWeights; j++)
            {
                if ((i == 0) || ( i == noOfExercises -1))
                {
                   operations += weightsArr[i][j];
                }
                
                if (i != 0)
                {
                    operations += abs(weightsArr[i-1][j] - weightsArr[i][j]);
                }
            }
        }
        printf("Case #%d: %d\n",testCaseId,operations);
        testCaseId ++;
    }
    return 0;
}