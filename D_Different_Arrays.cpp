#include <iostream>
using namespace std;
const int M = 1e5;
const int N = 305;
const int mod = 998244353;

int a[N];
long long dp[N][2 * M];

int main()
{
    iostream::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long n = 0, sum = 0, ans = 0;
    cin >> n;

    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        sum += a[i];
    }

    dp[1][a[3] + a[2] + M] = 1;
    dp[1][a[3] - a[2] + M] = 1;

    for (int i = 1; i <= n - 1; ++i)
    {
        for (int j = -sum; j <= sum; ++j)
        {
            if (j != 0)
            {
                dp[i + 1][a[i + 3] - j + M] += ((dp[i][j + M]) % mod);
                dp[i + 1][a[i + 3] + j + M] += ((dp[i][j + M]) % mod);
            }
            else
            {
                dp[i + 1][a[i + 3] + M] = dp[i][M] % mod;
            }
        }
    }

    // for(int i = 1; i <= n-1; i++)
    // {
    //     for(int j = -sum; j <=sum; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    for (int i = -sum; i <= sum; ++i)
    {
        ans += dp[n - 2][i + M];
        ans = ans % mod;
    }

    cout << ans << "\n";    
    return 0;
}
