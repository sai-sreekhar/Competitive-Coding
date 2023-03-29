// 1.	With a neat diagram, explain how a two-dimensional array is allocated in memory and also write a program to assign values in a 5 x 5 matrix as follows:
// a. (1,2,3…) in the upper triangle.
// b. (a,b,c,…)in the lower triangle.
// c. diagonal values are 0.
// Example:
// 0	1	2	3	4
// a	0	5	6	7
// b	c	0	8	9
// d	e	f	0	10
// g	h	i	j	0

#include <stdio.h>
int main()
{
    char a[5][5];
    int k = 1;
    int l = 97;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (i == j)
            {
                a[i][j] = 0;
            }
            else if (i < j)
            {
                a[i][j] = k;
                k++;
            }
            else
            {
                a[i][j] = l;
                l++;
            }
        }
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (i <= j)
            {
                printf("%d\t", a[i][j]);
            }
            else
            {
                printf("%c\t", a[i][j]);
            }
        }
        printf("\n");
    }
    return 0;
}