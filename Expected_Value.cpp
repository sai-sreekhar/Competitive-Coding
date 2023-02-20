/*
    Author: Sai Sreekar
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 998244353
typedef long double ld;

void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '"' << x << '"'; }
void __print(const string &x) { cerr << '"' << x << '"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V>
void __print(const pair<T, V> &x)
{
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
void __print(const T &x)
{
    int f = 0;
    cerr << '{';
    for (auto &i : x)
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

#define calc1 dp1[i - 1] + mul(binpow(temp, 2), inv) + mul(temp, dp2[i - 1])
#define calc2 (dp2[i - 1] + mul(temp, inv)) % mod
#ifndef ONLINE_JUDGE
#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define debug(x...)
#endif

ll mul(ll a, ll b)
{
    return ((a % mod) * (b % mod)) % mod;
}

ll binpow(ll a, ll b)
{
    if (b == 0)
    {
        return 1;
    }
    ll tmp = binpow(a, b / 2);
    tmp = mul(tmp, tmp);
    if (b % 2)
    {
        return mul(tmp, a);
    }
    return tmp;
}

ll mod_inverse(ll a, ll m = mod)
{
    return binpow(a, m - 2);
}

void solve()
{
    ll N, P;
    cin >> N >> P;

    vector<ll> dp1(N + 1, 0), dp2(N + 1, 0);
    dp1[1] = dp2[1] = mod_inverse(2);

    ll inv = mod_inverse(2);
    for (ll i = 2; i <= N; i++)
    {
        ll temp = mod_inverse(binpow(P, i - 1));
        ll val = (calc1) % mod;
        dp1[i] = val;
        dp2[i] = calc2;
    }

    for (ll i = 1; i <= N; i++)
    {
        cout << dp1[i] << ' ';
    }
    cout << endl;
}

int main()
{
    solve();
    return 0;
}