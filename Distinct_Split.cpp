/*
    Author: Sai Sreekar
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
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

#ifndef ONLINE_JUDGE
#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define debug(x...)
#endif

void func(map<char, ll> &mp, vector<ll> &v, string &s, ll n, ll k)
{
    if (k == 0)
    {
        v[0] = 1;
        mp[s[0]]++;
        for (ll i = 1; i < n; i++)
        {
            if (mp.find(s[i]) == mp.end())
            {
                v[i] = v[i - 1] + 1;
            }
            else
            {
                v[i] = v[i - 1];
            }
            mp[s[i]]++;
        }
    }
    else
    {
        v[n - 1] = 1;
        mp[s[n - 1]]++;
        for (ll i = n - 2; i >= 0; i--)
        {
            if (mp.find(s[i]) == mp.end())
            {
                v[i] = v[i + 1] + 1;
            }
            else
            {
                v[i] = v[i + 1];
            }
            mp[s[i]]++;
        }
    }
}

void solve()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;
    vector<ll> v1(n, 0);
    vector<ll> v2(n, 0);
    map<char, ll> mp1;
    map<char, ll> mp2;

    func(mp1, v1, s, n, 0);
    func(mp2, v2, s, n, 1);
    // debug(v1, v2, mp1, mp2);
    ll ans = 0;
    ans = v2[0];
    for (ll i = 0; i < n - 1; i++)
    {
        ans = max(ans, v1[i] + v2[i + 1]);
    }
    ans = max(ans, v2[n - 1]);

    // for (ll i = 0; i < n; i++)
    // {
    //     ans = max(ans, v2[i] + v2[i + 1]);
    // }

    if (ans > n)
    {
        cout << n << endl;
        return;
    }

    cout << ans << endl;
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

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}