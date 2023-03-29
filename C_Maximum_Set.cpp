/*
    Author: Sai Sreekar
    Created: 2023/02/28 21:11:52
    Last Modified: 2023/02/28 21:58:06
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
#define res cout << j << " " << (p1.second - p1.first + 1) * j + p2.second - p2.first + 1 << "\n";
#define funCall                              \
    pair<ll, ll> p1 = func3(n, k, j, func1); \
    pair<ll, ll> p2 = func3(p1.second + 1, k, j, func2);

#define binarySearch          \
    ll mid = (l + r) / 2;     \
    if ((f(mid, j)) <= right) \
    {                         \
        l = mid + 1;          \
        temp = mid;           \
    }                         \
    else                      \
    {                         \
        r = mid - 1;          \
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

#define edgeCase cout << 1 << " " << k - n + 1 << "\n";
ll func1(ll n, ll k)
{
    return (n << (k - 2)) * 3;
}

ll func2(ll n, ll k)
{
    return n << (k - 1);
}

pair<ll, ll> func3(ll l, ll r, ll j, function<ll(ll, ll)> f)
{
    ll temp = l - 1;
    ll right = r;
    ll left = l;

    while (l <= r)
    {
        binarySearch;
    }

    return {left, temp};
}

void solve()
{
    ll n, k;
    cin >> n >> k;
    ll i = k;
    ll j = 0;
    while (i >= n)
    {
        i /= 2;
        j++;
    }

    if (j == 1)
    {
        edgeCase;
        return;
    }

    funCall;
    res;
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