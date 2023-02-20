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

#define calc1 d + 1 - (pos[arr[i + 1]] - pos[arr[i]])
#define calc2 (n - pos[arr[i + 1]] + pos[arr[i]] - 1)
void solve()
{
    ll n, m, d;
    cin >> n >> m >> d;
    vector<ll> permutation(n);
    vector<ll> arr(m);
    map<ll, ll> pos;

    for (ll i = 0; i < n; i++)
    {
        cin >> permutation[i];
        pos[permutation[i]] = i + 1;
    }
    for (ll i = 0; i < m; i++)
    {
        cin >> arr[i];
    }

    ll res = INT_MAX;
    // for(ll i = 0; i < m; i++)
    // {
    //     cout << pos[arr[i]] << " ";
    // }

    // for(ll i = 0; i < m - 1; i++)
    // {
    //     if(pos[arr[i]] >= pos[arr[i + 1]] || pos[arr[i + 1]] > pos[arr[i]] + d)
    //     {
    //         cout << 0 << endl;
    //         return;
    //     }
    // }
    for (ll i = 0; i < m - 1; i++)
    {
        if (pos[arr[i]] >= pos[arr[i + 1]] || pos[arr[i + 1]] > pos[arr[i]] + d)
        {
            cout << 0 << endl;
            return;
        }
        
        ll diff = pos[arr[i + 1]] - pos[arr[i]];
        res = min(res, diff);
        if (calc1 <= calc2)
        {
            res = min(res, calc1);
        }
    }

    cout << res << endl;
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