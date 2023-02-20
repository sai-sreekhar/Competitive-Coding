#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ONLINE_JUDGE
#define DEBUG_CODE

#ifdef DEBUG_CODE
#define TRACE(msg, ...) printTrace(__LINE__, __FILE__, msg, __VA_ARGS__)
#define PRINT_ARRAY(arr, n, type) myPrint<type>(arr, n)
#else
#define TRACE(msg, ...)
#define PRINT_ARRAY(arr, n, type)
#endif

template <typename T1>
void myPrint(T1 *arr, int n)
{
    cout << "myPrint Function output is: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void printTrace(int line, const char *fileName, const char *msg, ...)
{
    va_list args;
    char buffer[1024 + 2] = {0};
    snprintf(buffer, sizeof(buffer), "%s(%d) : ", fileName, line);
    int stringLength = strnlen(buffer, 1024);
    int remainingBufferSize = 1024 - stringLength;
    va_start(args, msg);
    vsnprintf(buffer + stringLength, remainingBufferSize, msg, args);
    va_end(args);
    cout << buffer << "\n"
         << flush;
}

ll fillMap(map<ll, ll> &mp, ll n)
{
    ll k = n;
    ll maxi = 1;

    for (ll i = 2; i * i <= n; i++)
    {
        if (k % i == 0)
        {
            ll temp = 0;
            while (k % i == 0)
            {
                temp++;
                k /= i;
            }

            mp[i] = temp;
            maxi = max(maxi, temp);
        }
    }

    if (k != 1)
    {
        mp[k] = 1;
    }
    return maxi;
}

void solve()
{
    ll n;
    cin >> n;
    map<ll, ll> mp;

    ll maxi = fillMap(mp, n);

    ll ans = 0;
    // for(auto itr = mp.begin(); itr != mp.end(); itr++)
    // {
    //     cout << itr->first << " " << itr->second << "\n";
    // }
    // cout << maxi << "\n";
    for (ll i = 0; i < maxi; i++)
    {
        ll cur = 1;
        for (auto itr = mp.begin(); itr != mp.end(); itr++)
        {
            if (itr->second > 0)
            {
                mp[itr->first] -= 1;
                cur *= itr->first;
            }
        }
        ans += cur;
    }

    cout << ans << "\n";
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