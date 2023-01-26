#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int T = 1;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d", &n);

        int a[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }

        if (n == 1)
        {
            printf("1\n");
            continue;
        }

        int res = 1;

        for (int i1 = 0; i1 < n; i1++)
        {
            for (int i2 = i1 + 1; i2 < n; i2++)
            {
                // if (n - i2 + 1 <= res)
                // {
                //     break;
                // }

                int delta = a[i2] - a[i1];
                for (int i = 1; i * i <= delta; i++)
                {
                    if (delta % i != 0)
                    {
                        continue;
                    }

                    int j = delta / i;
                    if (j <= i || (j - i) % 2 != 0)
                    {
                        continue;
                    }

                    ll x = (j - i) / 2;
                    ll inc = x * x - a[i1];
                    if (inc < 0)
                    {
                        continue;
                    }

                    int cnt = 2;
                    for (int k = i2 + 1; k < n; k++)
                    {
                        ll num = a[k] + inc;
                        if (ceil(sqrt(num)) == floor(sqrt(num)))
                        {
                            cnt++;
                        }
                    }
                    res = max(res, cnt);
                }
            }
        }

        printf("%d\n", res);
    }
    return 0;
}

// a[j] - a[i] = y^2 - x^2 = (y + x) * (y - x)