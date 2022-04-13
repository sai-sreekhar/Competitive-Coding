#include <stdio.h>

int main()
{
    int num1, num2, *gcd, i;
    scanf("%d", &num1);
    scanf("%d", &num2);
    int *pointerToNum1 = &num1;
    int *pointerToNum2 = &num2;

    for (i = 1; ((i <= *pointerToNum1) && (i <= *pointerToNum2)); i++)
    {
        if ((*pointerToNum1 % i == 0) && (*pointerToNum2 % i == 0))
        {
            *gcd = i;
        }
    }
    printf("%d", *gcd);
    return 0;
}