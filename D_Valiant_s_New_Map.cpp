#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int sparseTable[n][m][10];
        int arr[n][m];
        memset(&sparseTable, -1, sizeof(sparseTable));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> arr[i][j];
                sparseTable[i][j][0] = arr[i][j];
            }
        }

        for (int k = 1; pow(2, k) <= (min(n, m)); k++)
        {
            for (int i = 0; i + pow(2, k) - 1 < n; i++)
            {
                for (int j = 0; j + pow(2, k) - 1 <= m; j++)
                {
                    int a = pow(2, k - 1);
                    sparseTable[i][j][k] = min(min(sparseTable[i][j][k - 1], sparseTable[i + a][j][k - 1]), min(sparseTable[i][j + a][k - 1], sparseTable[i + a][j + a][k - 1]));
                }
            }
        }

        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < m; j++)
        //     {
        //         cout << sparseTable[i][j][1] << " ";
        //     }
        //     cout << "\n";
        // }

        int l = 1;
        int r = min(n, m);
        while (l < r)
        {
            int x = (l + r + 1) / 2;
            int z = 0;
            int p = log2(x);
            for (int i = 0; i + x <= n; i++)
            {
                for (int j = 0; j + x <= m; j++)
                {
                    int power = pow(2, p);
                    if (min(min(sparseTable[i][j][p], sparseTable[i + x - power][j + x - power][p]), min(sparseTable[i][j + x - power][p], sparseTable[i + x - power][j][p])) >= x)
                    {
                        z = 1;
                    }
                }
                if (z == 1)
                {
                    break;
                }
            }

            if (z)
            {
                l = x;
            }
            else
            {
                r = x - 1;
            }
        }
        cout << l << "\n";
    }
}