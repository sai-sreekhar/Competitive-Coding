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
        int arr[200005] = {0};
        // for (int i = 1; i < n; i++)
        // {
        //     cin >> arr[i];
        // }

        int res = -1;
        // for (int i = n - 1; i >= 0; i--)
        // {
        //     for (int j = i; j >= 0; j--)
        //     {
        //         if (__gcd(arr[i], arr[j]) == 1)
        //         {
        //             res = max(res, i + j + 2);
        //         }
        //     }
        // }

        int isPresentArr[1001] = {0};
        int indexArray[1001] = {0};
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
            isPresentArr[arr[i]] = 1;
            indexArray[arr[i]] = i;
        }

        for (int i = 1; i <= 1000; i++)
        {
            for (int j = 1; j <= 1000; j++)
            {
                if (isPresentArr[i] && isPresentArr[j] && gcd(i, j) == 1)
                {
                    res = max(res, indexArray[i] + indexArray[j]);
                }
            }
        }
        cout << res << "\n";
    }

    return 0;
}
