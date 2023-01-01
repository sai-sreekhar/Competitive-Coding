#include <bits/stdc++.h>
using namespace std;

#define ll long long

void getNumberOfSubArrays()
{
    ll n;
    cin >> n;
    ll arr[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    ll maxXOR = n;
    ll i = -1;
    ll tempXOR = 0;
    ll res = 0;
    ll count = 0;
    while (count <= sqrt(2 * n))
    {
        i++;
        tempXOR = i * i;

        ll prefixXOR = 0;
        ll tempArr[2 * n] = {0};
        for (ll j = 0; j < n; j++)
        {
            prefixXOR ^= arr[j];
            if (prefixXOR == tempXOR)
            {
                res++;
            }
            
            if (((prefixXOR ^ tempXOR) < (2*n)) && (tempArr[prefixXOR ^ tempXOR] != 0))
            {
                res += tempArr[prefixXOR ^ tempXOR];
            }

            tempArr[prefixXOR]++;
        }
        count++;
    }

    cout << n * (n + 1) / 2 - res << "\n";
}

int main()
{
    ll testCases;
    cin >> testCases;
    while (testCases--)
    {
        getNumberOfSubArrays();
    }
    return 0;
}