#include <bits/stdc++.h>

using namespace std;

#define ONLINE_JUDGE

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
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
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        int x = arr[0];
        for (int i = 1; i < n; i++)
            x = gcd(x, arr[i]);

        if (x == 1)
            cout << 0 << endl;
        else if (gcd(x, n) == 1)
            cout << 1 << endl;
        else if (gcd(x, n - 1) == 1)
            cout << 2 << endl;
        else
            cout << 3 << endl;
    }

    return 0;
}


