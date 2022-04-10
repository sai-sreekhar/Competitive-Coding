#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>

#define MAX_LEN 101
int main()
{
    int noOftestCases;
    scanf("%d",&noOftestCases);
    
    int testCaseId = 1;
    
    while (testCaseId <= noOftestCases)
    {
        char str[MAX_LEN];
        scanf("%s",str);
        char newStr[MAX_LEN];
        int idx = 0;
        int i = 0;
        while ( i < strlen(str)-1)
        {
            if ((int)(str[i]) < (int)(str[i+1]))
            {
                newStr[idx] = str[i];
                idx++;
                newStr[idx] = str[i];
                idx ++;
                i++;
            }
            else if ((int)(str[i]) > (int)(str[i+1]))
            {
                newStr[idx] = str[i];
                idx++;
                i++;
            }
            else
            {
                char presentChar = str[i];
                int j = i;
                while ((str[j+1] == str[j+2]) && (j+2 <= strlen(str)))
                {
                    j++;
                }
                
                if ((int)(str[j +1]) < (int)(str[j +2]))
                {
                    int count = j + 2 -i;
                    while (count > 0)
                    {
                        newStr[idx] = presentChar;
                        idx++;
                        newStr[idx] = presentChar;
                        idx++;
                        count --;
                    }
                }
                else
                {
                   int count = j + 2 -i;
                    while (count > 0)
                    {
                        newStr[idx] = presentChar;
                        idx++;
                        count --;
                    } 
                }
                i = j+2;
            }
        }
        if (str[i] != '\0')
        {
            newStr[idx] = str[strlen(str)-1];
            newStr[idx+1] = '\0';
        }
        else
        {
            newStr[idx] = '\0';
        }
        printf("Case #%d: %s\n",testCaseId,newStr);   
        testCaseId ++;
    }
    
    return 0;
}