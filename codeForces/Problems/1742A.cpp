#include <bits/stdc++.h>

using namespace std;

// #define ONLINE_JUDGE

#define ll long long

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
        int a, b, c;
        cin >> a >> b >> c;
        int minNum = min(min(a, b), min(b, c));
        int maxNum = max(max(a, b), max(b, c));
        // cout << minNum << " " << maxNum << endl;
        if (2 * maxNum == (a + b + c))
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }

    return 0;
}
