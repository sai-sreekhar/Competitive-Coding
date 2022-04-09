#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>

int *sortArr(int *, int, int);

int main()
{
    int noOfIntegers;
    int userChoice;
    scanf("%d", &noOfIntegers);

    if (noOfIntegers < 0)
    {
        printf("Invalid input\n");
        return 0;
    }
    

    int arr[noOfIntegers];

    for (int i = 0; i < noOfIntegers; i++)
    {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &userChoice);

    if ((userChoice != 1) && (userChoice != 2))
    {
        printf("Invalid input\n");
        return 0;
    }

    int *sortedArr = sortArr(arr, noOfIntegers,userChoice);

    for (int i = 0; i < noOfIntegers; i++)
    {
        printf("%d\n", arr[i]);
    }

    return 0;
}

int *sortArr(int *arr, int n, int choice)
{
    int i, j;
    bool swapped;
    if (choice == 1)
    {
        for (i = 0; i < n - 1; i++)
        {
            swapped = false;
            for (j = 0; j < n - i - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    int temp = arr[j + 1];
                    arr[j + 1] = arr[j];
                    arr[j] = temp;
                    swapped = true;
                }
            }

            if (swapped == false)
            {  
                  break;
            }
        }
    }
    else
    {
        for (i = 0; i < n - 1; i++)
        {
            swapped = false;
            for (j = 0; j < n - i - 1; j++)
            {
                if (arr[j] < arr[j + 1])
                {
                    int temp = arr[j + 1];
                    arr[j + 1] = arr[j];
                    arr[j] = temp;
                    swapped = true;
                }
            }

            if (swapped == false)
            {
                break;
            }
        }
    }

    return arr;
}