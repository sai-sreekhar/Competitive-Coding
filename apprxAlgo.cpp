#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, i = 0, j = 0, count = 0, vertex_flag;
    scanf("%d", &n);
    int **graph = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
        graph[i] = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);
    int *answer = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
        scanf("%d", &answer[i]);
    int *flag = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
        flag[i] = 0;
    for (i = 0; i < n; i++)
    {
        if (answer[i] == 1)
        {
            for (j = 0; j < n; j++)
            {
                if (graph[i][j] == 1)
                    flag[j] += 1;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        if (answer[i] == 1)
        {
            vertex_flag = 1;
            for (j = 0; j < n; j++)
            {
                if (graph[i][j] == 1 && flag[j] <= 1)
                    vertex_flag = 0;
            }
            if (vertex_flag)
            {
                flag[i] += 1;
            }
        }
    }
    for (i = 0; i < n; i++)
        if (flag[i] >= 1)
        {
            count++;
        }
    if (count == n)
        printf("\nTrue\n");
    else
        printf("\nFalse\n");
    return 0;
}
