#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>

#define SUCCESS 0
#define FAILURE 1
#define MAX_LIMIT 101

int main()
{
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        char word[MAX_LIMIT];
        scanf("%s",word);
        if (strlen(word) <= 10)
        {
            printf("%s\n",word);
        }
        else
        {
            printf("%c",word[0]);
            printf("%ld",strlen(word)-2);
            printf("%c\n",word[strlen(word)-1]);
        }
        
    }
    
    return SUCCESS;
}