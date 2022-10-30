#include <bits/stdc++.h>

using namespace std;

// #define ONLINE_JUDGE

#define ll long long

void solve()
{
    ll n, q;
    cin >> n >> q;

    vector<ll> vec(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> vec[i];
    }

    vector<ll> prefixSumVec(n + 1, 0);
    vector<ll> prefixXorVec(n + 1, 0);

    ll l, r;
    cin >> l >> r;

    ll sum1 = 0;
    ll xor1 = 0;

    for (int i = 1; i <= n; i++)
    {
        sum1 += vec[i];
        xor1 ^= vec[i];

        prefixSumVec[i] = sum1;
        prefixXorVec[i] = xor1;
    }

    ll res = sum1 - xor1;

    ll low = l;
    ll high = r;

    ll ind1 = 1, ind2 = n;

    while (low <= high)
    {
        ll mid = (low + high) / 2;

        bool check = false;
        for (int i = 1; i <= n - mid + 1; i++)
        {
            if (((prefixSumVec[i + mid - 1] - prefixSumVec[i - 1]) - (prefixXorVec[i + mid - 1] ^ prefixXorVec[i - 1])) == res)
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
