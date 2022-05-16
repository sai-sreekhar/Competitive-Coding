#include <stdio.h>

int getSeriesNumber(int n_064);

int main()
{
    int n_064;
    scanf("%d", &n_064);

    for (int i = 1; i <= n_064; i++)
    {
        printf("L%d = %d\n", i, getSeriesNumber(i));
    }

    return 0;
}

int getSeriesNumber(int n_064)
{
    if (n_064 == 1)
    {
        return 1;
    }

    if (n_064 == 2)
    {
        return 3;
    }

    return 3*getSeriesNumber(n_064-1) + 2*getSeriesNumber(n_064-2);
}