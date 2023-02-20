/*
    Author: Sai Sreekar
*/

#include <bits/stdc++.h>
#define calc1 ((n * inv[i] % mod + (n * inv[i] % mod - 1) * temp1 % mod) % mod + mod) % mod
using namespace std;

typedef long long ll;
typedef long double ld;

void __print(int temp1) { cerr << temp1; }
void __print(long temp1) { cerr << temp1; }
void __print(long long temp1) { cerr << temp1; }
void __print(unsigned temp1) { cerr << temp1; }
void __print(unsigned long temp1) { cerr << temp1; }
void __print(unsigned long long temp1) { cerr << temp1; }
void __print(float temp1) { cerr << temp1; }
void __print(double temp1) { cerr << temp1; }
void __print(long double temp1) { cerr << temp1; }
void __print(char temp1) { cerr << '\'' << temp1 << '\''; }
void __print(const char *temp1) { cerr << '"' << temp1 << '"'; }
void __print(const string &temp1) { cerr << '"' << temp1 << '"'; }
void __print(bool temp1) { cerr << (temp1 ? "true" : "false"); }
#define calc2 (temp2 + (i <= str) * temp1) % mod
template <typename T, typename V>
void __print(const pair<T, V> &temp1)
{
    cerr << '{';
    __print(temp1.first);
    cerr << ',';
    __print(temp1.second);
    cerr << '}';
}
template <typename T>
void __print(const T &temp1)
{
    int f = 0;
    cerr << '{';
    for (auto &i : temp1)
        cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v)
{
    __print(t);
    if (sizeof...(v))
        cerr << ", ";
    _print(v...);
}

#define res ((temp1 * n + n + temp2 - temp1) % mod + mod) % mod - 1

#ifndef ONLINE_JUDGE
#define debug(temp1...)               \
    cerr << "[" << #temp1 << "] = ["; \
    _print(temp1)
#else
#define debug(temp1...)
#endif

ll n, str, temp1, temp2, inv[1000001];
ll mod = 998244353;

void getInv()
{
    inv[0] = inv[1] = 1;
    for (ll i = 2; i <= 1000000; i++)
    {
        inv[i] = mod - mod / i * inv[mod % i] % mod;
    }
}

void solve()
{
    str = 0;
    temp1 = 1;
    temp2 = 1;

    string a, b;
    ll n;
    cin >> n >> a >> b;
    for (ll i = 0; i < n; i++)
    {
        str += a[i] != b[i];
    }

    for (ll i = n; i >= 2; i--)
    {
        temp1 = calc1;
        temp2 = calc2;
    }

    //     for(ll i = 1; i <= str; i++)
    //     {
    //         temp1 = (temp1 * i) % mod;
    //     }

    // for(ll i = 1; i <= n - str; i++)
    // {
    //     temp2 = (temp2 * i) % mod;
    // }
    if (str == 0)
    {
        cout << 0 << "\n";
        return;
    }

    cout << res << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // #ifndef ONLINE_JUDGE
    //	freopen("in.txt", "r", stdin);
    //	freopen("out.txt", "w", stdout);
    // #endif
    getInv();

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}