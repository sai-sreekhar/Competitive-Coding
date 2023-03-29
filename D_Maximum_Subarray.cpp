/*
    Author: Sai Sreekar
    Created: 2023/02/28 20:45:07
    Last Modified: 2023/03/01 17:26:26
*/

#include <bits/stdc++.h>

using namespace std;

// typedefs
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double lld;
typedef vector<ll> vll;
typedef vector<pair<ll, ll>> vpll;
typedef pair<ll, ll> pll;

// Debug Utils
#ifndef ONLINE_JUDGE
#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define debug(x...)
#endif

void __print(int x)
{
    cerr << x;
}
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

template <typename... Params>
void _print(priority_queue<Params...> q)
{
    while (!q.empty())
    {
        cerr << " " << q.top() << ",";
        q.pop();
    }
    cerr << "]" << endl;
}

// Operator Overloads
template <typename T1, typename T2>
istream &operator>>(istream &istream, pair<T1, T2> &p) { return (istream >> p.first >> p.second); }
template <typename T>
istream &operator>>(istream &istream, vector<T> &v)
{
    for (auto &it : v)
        cin >> it;
    return istream;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &ostream, const pair<T1, T2> &p) { return (ostream << p.first << " " << p.second << "\n"); }
template <typename T>
ostream &operator<<(ostream &ostream, const vector<T> &c)
{
    for (auto &it : c)
        cout << it << " ";
    return ostream;
}

ll res = LLONG_MIN;
ll maxSubArraySum(vll a, int n)
{
    ll maxi1 = LLONG_MIN;
    ll maxi2 = 0;

    for (ll i = 0; i < n; i++)
    {
        maxi2 = maxi2 + a[i];
        if (maxi1 < maxi2)
        {
            maxi1 = maxi2;
        }

        if (maxi2 < 0)
        {
            maxi2 = 0;
        }
    }
    return maxi1;
}

const ll N = 2e5 + 5;
ll n, k, x, a[N], dp[N][25];

void solve()
{
    cin >> n >> k >> x;
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    ll mx = 0;
    for (ll i = 1; i <= n; i++)
    {
        dp[i][0] = max(dp[i - 1][0] + a[i] - x, 0ll);
        if (n - i >= k)
        {
            mx = max(mx, dp[i][0]);
        }

        for (ll j = 1; j <= k && j <= i; j++)
        {
            dp[i][j] = max(dp[i - 1][j - 1] + a[i] + x, 0ll);
            if (i - 1 >= j)
            {
                dp[i][j] = max(dp[i - 1][j] + a[i] - x, dp[i][j]);
            }
            if (n - i >= k - j)
            {
                mx = max(mx, dp[i][j]);
            }
        }
    }

    for (ll i = 0; i <= n; i++)
    {
        for (ll j = 0; j <= k; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    cout << "res: " << mx << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // #ifndef ONLINE_JUDGE
    // freopen("in.txt","r", stdin);
    // freopen("out.txt", "w", stdout);
    // #endif

    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
#ifndef ONLINE_JUDGE
        cerr << "\nTest Case #" << i << ":"
             << "\n";
#endif
        solve();
    }

#ifndef ONLINE_JUDGE
    cerr << "\nTime Taken: " << (float)clock() / CLOCKS_PER_SEC << " sec"
         << "\n";
#endif

    return 0;
}