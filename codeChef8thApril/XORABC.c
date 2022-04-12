#include <stdio.h>
int main() 
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        int a;
        scanf("%d",&a);   
        if (a == (a & ~(a-1)))
        {
            printf("%d\n",-1);
        }
        else
        {
            if ((a & ~(a-1)) % 2 != 0)
            {
                printf("%d\n",-1);
            }
            else
            {
                printf("%d %d %d\n",(a & ~(a-1))/2, a/2, (a-(a & ~(a-1)))/2);
            }
        }
    }
    return 0;
}