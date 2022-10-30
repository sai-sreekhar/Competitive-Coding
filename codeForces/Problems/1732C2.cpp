#include <bits/stdc++.h>

using namespace std;

// #define ONLINE_JUDGE

void solve()
{
    int n, q;
    cin >> n >> q;

    vector<int> vec(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> vec[i];
    }

    vector<int> prefixSumVec(n + 1, 0);
    vector<int> prefixXorVec(n + 1, 0);

    while (q--)
    {

        int l, r;
        cin >> l >> r;

        int sum1 = 0;
        int xor1 = 0;

        for (int i = 1; i <= n; i++)
        {
            sum1 += vec[i];
            xor1 ^= vec[i];

            prefixSumVec[i] = sum1;
            prefixXorVec[i] = xor1;
        }

        int low = l;
        int high = r;

        int ind1 = l, ind2 = r;
        while (low <= high)
        {
            int mid = (low + high) / 2;

            bool check = false;
            for (int i = low; i <= high - mid + 1; i++)
            {
                if (((prefixSumVec[i + mid - 1] - prefixSumVec[i - 1]) - (prefixXorVec[i + mid - 1] ^ prefixXorVec[i - 1])) == prefixSumVec[r + l - 1] - prefixSumVec[l - 1] - (prefixXorVec[r + l - 1] ^ prefixXorVec[l - 1]))
                {
                    check = true;
                    ind1 = i;
                    ind2 = i + mid - 1;
                    break;
                }
            }

            if (check == true)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        cout << ind1 << " " << ind2 << "\n";
    }

    return;
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
