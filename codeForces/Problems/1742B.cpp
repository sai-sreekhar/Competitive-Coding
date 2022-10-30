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
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr, arr + n);
        bool flag = false;
        for (int i = 1; i < n; i++)
        {
            if (arr[i] == arr[i - 1])
            {
                flag = true;
                break;
            }
        }
        if (flag)
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
        }
    }

    return 0;
}
