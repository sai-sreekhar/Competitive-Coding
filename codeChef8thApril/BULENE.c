#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>

int main()
{
    int noOfTestCases;
    scanf("%d",&noOfTestCases);

    while (noOfTestCases --)
    {
        int noOfEnemies,noOfBullets;
        scanf("%d %d",&noOfEnemies,&noOfBullets);

        int enemyCapArr[noOfEnemies];
        int bulletPowArr[noOfBullets];
        int bulletCapArr[noOfBullets];

        for (int i = 0; i < noOfEnemies; i++)
        {
            scanf("%d",&enemyCapArr[i]);
        }
        for (int i = 0; i < noOfBullets; i++)
        {
            scanf("%d",&bulletPowArr[i]);
        }
        for (int i = 0; i < noOfBullets; i++)
        {
            scanf("%d",&bulletCapArr[i]);
        }
        
        for (int i = 0; i < noOfBullets; i++)
        {
            int bulletCap = bulletCapArr[i];
            int j = 0;
            int enemiesShot = 0;
            while ((enemiesShot < bulletCap) && (j < noOfEnemies))
            {
                if (enemyCapArr[j] > 0)
                {
                    if (enemyCapArr[j] - bulletPowArr[i] <= 0)
                    {
                        enemyCapArr[j] = 0;
                        enemiesShot++;
                    }
                    else
                    {
                        enemyCapArr[j] = enemyCapArr[j] - bulletPowArr[i];
                        enemiesShot++;
                    }
                }
                j++;
            }
        }

        for (int i = 0; i < noOfEnemies; i++)
        {
            printf("%d ",enemyCapArr[i]);
        }
        printf("\n");
    }
    return 0;
}