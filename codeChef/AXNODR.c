#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>

int main()
{
    int noOfTestCases = 0;
    scanf("%d",&noOfTestCases);

    while (noOfTestCases --)
    {
        long n;
        scanf("%ld",&n);

        if ((n % 4 == 2) || ((n % 4 == 3)))
        {
            printf("%ld\n",(long)3);
        }
        else if (n % 4 == 0)
        {
            printf("%ld\n",n + 3);
        }
        else
        {
            printf("%ld\n",n);
        }   
    }
    
    return 0;
}