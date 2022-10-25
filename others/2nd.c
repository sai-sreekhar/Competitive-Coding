#include <stdio.h>

int findMaxRowSumAndIdx(int n_064, int matrix_064[n_064][n_064]);
int main()
{
    int n_064;
    scanf("%d",&n_064);
    int matrix_064[n_064][n_064];
    

    printf("Enter %dX%d array\n",n_064,n_064);
    for (int i = 0; i < n_064; i++)
    {
        for (int j = 0; j < n_064; j++)
        {
            scanf("%d",&matrix_064[i][j]);
        }
    }
    
    printf("Index:%d\n",findMaxRowSumAndIdx(n_064,matrix_064));
    return 0;
}

int findMaxRowSumAndIdx(int n_064, int matrix_064[n_064][n_064])
{
    int maxRowSum_064 = 0;
    int maxRowIdx_064 = 0;

    for (int row = 0; row < n_064; row++)
    {
        int rowSum = 0;
        for (int col = 0; col < n_064; col++)
        {
            rowSum += matrix_064[row][col];
        }

        if (rowSum > maxRowSum_064)
        {
            maxRowSum_064 = rowSum;
            maxRowIdx_064 = row;
        }
    }

    printf("Sum:%d\n",maxRowSum_064);
    return maxRowIdx_064;
}