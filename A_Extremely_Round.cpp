#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    if (n <= 9)
    {
        cout << n << "\n";
        return;
    }
    int c = 9;
    int divisor = 10;
    while (n / divisor > 0)
    {
        if (n / divisor >= 10)
        {
            c += 9;
        }
        else
        {
            c += (n / divisor);
        }
        divisor *= 10;
    }
    cout << c << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}