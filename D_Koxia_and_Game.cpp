#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

int t, n;
int a[100005], b[100005], cnt[100005];

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n;

        // Clear the cnt array for the current test case
        memset(cnt, 0, sizeof(cnt));

        // Read in the arrays a and b and update the cnt array
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            cnt[a[i]]++;
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> b[i];
            cnt[b[i]]++;
        }

        // Initialize the result to 0
        int res = 0;

        // Iterate over all possible values of c[i]
        for (int i = 1; i <= n; i++)
        {
            // If c[i] is not present in a or b, Koxia wins
            if (cnt[i] == 0)
                res = (res + 1) % mod;

            // If c[i] is present in both a and b, Koxia can choose
            // either a[i] or b[i] and Mahiru will be forced to choose
            // the other element, which is not in c. Therefore, Koxia wins.
            if (cnt[i] == 2)
                res = (res + 1) % mod;
        }

        cout << res << endl;
    }
}
