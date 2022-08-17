#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>

#define SUCCESS 0
#define FAILURE 1

int main()
{
    int weight = 0;
    scanf("%d",&weight);
    if ((weight % 2 != 0)||(weight == 2))
    {
        printf("NO");
    }
    else
    {
        printf("YES");
    }
    
    return SUCCESS;
}