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

bool compare(pair<int, int> a, pair<int, int> b)
{
    return a.first < b.first;
}

void solve()
{
    ll n;
    cin >> n;
    vector<ll> health(n);
    vector<ll> spell(n);
    vector<pair<ll, ll>> vec(n);

    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> health[i];
        ans += health[i];
    }

    for (ll i = 0; i < n; i++)
    {
        cin >> spell[i];
        vec[i].first = spell[i];
        vec[i].second = i + 1;
    }

    sort(vec.begin(), vec.end(), compare);
    debug(vec);
    debug(spell);

    for (ll i = 0; i < n; i++)
    {
        if (i != n - 1)
        {
            ans += vec[i].first;
        }
    }

    cout << ans << endl;
    return;
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