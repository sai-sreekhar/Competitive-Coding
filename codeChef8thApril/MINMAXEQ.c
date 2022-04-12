#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>

int getMaxIdx(int arr[],int n);

int main()
{
    int noOfTestCases;
    scanf("%d",&noOfTestCases);
    while (noOfTestCases --)
    {
        int len;
        int chances;
        scanf("%d %d",&len,&chances);

        int arr[len];
        for (int i = 0; i < len; i++)
        {
            scanf("%d",&arr[i]);
        }

        int i = 0;
        int pvsNum = -1;
        int newArr[100000] = {0};
        int idx = -1;

        while (i < len-1)
        {
            //getting count of consecutive occurences
            if ((arr[i] == arr[i+1]) && (pvsNum != arr[i]))
            {
                pvsNum = arr[i];
                idx++;
                newArr[idx]++;
            }
            else if ((arr[i] == arr[i+1]) && (pvsNum == arr[i]))
            {
                newArr[idx]++;
            }
            i++;
        }

        int maxIdx;
        while (chances != 0)
        {
            maxIdx = getMaxIdx(newArr,idx);//getting index of max ocuurences value
            if ((newArr[maxIdx] % 2 == 0) && (newArr[maxIdx] > 0))
            {
                if ((newArr[maxIdx]-2) > 0)//changing the middle most element and changing the newArr accordingly
                {
                    idx ++;
                    newArr[idx] = (newArr[maxIdx]-2)/2;
                    idx ++;
                    newArr[idx] = (newArr[maxIdx]-2)/2;
                }

                newArr[maxIdx] = 0;            
            }
            else
            {
                if (((newArr[maxIdx]-1) > 0) && (newArr[maxIdx] > 0))
                {
                    idx ++;
                    newArr[idx] = (newArr[maxIdx]-1)/2; 
                }

                if (((newArr[maxIdx] -3) > 0) && (newArr[maxIdx] > 0))
                {
                    idx ++;
                    newArr[idx] = (newArr[maxIdx]-3)/2;
                }

                newArr[maxIdx] = 0; 
            }

            chances --;
        }

        int minBadSubArrays = len;
        for (int i = 0; i < idx+1; i++)
        {
            if (newArr[i] > 0)
            {
                minBadSubArrays += (newArr[i]*(newArr[i]+1))/2;
            }
        }
        printf("%d\n",minBadSubArrays);

    }    
    return 0;
}

int getMaxIdx(int *arr,int n)
{
    int max = arr[0];
    int idx = 0;

    for (int i = 1; i < n+1; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            idx = i;
        }
        
    }
    return idx;
}