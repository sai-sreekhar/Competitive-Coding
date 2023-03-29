/*
    Author: Sai Sreekar
    Created: 2023/03/26 18:40:22
    Last Modified: 2023/03/26 18:51:10
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

#define calc1                                  \
    gcdVal = __gcd(gcdVal, vec1[i] * vec2[i]); \
    ll tempVar = vec2[i] / __gcd(lowLim, vec2[i]);

#define cond2                       \
                                    \
    lowLim *= tempVar;              \
    if (gcdVal % lowLim != 0)       \
    {                               \
        output++;                   \
        lowLim = vec2[i];           \
        gcdVal = vec1[i] * vec2[i]; \
    }

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

#define cond1                       \
    if (tempVar > gcdVal / lowLim)  \
    {                               \
        output++;                   \
        lowLim = vec2[i];           \
        gcdVal = vec1[i] * vec2[i]; \
        continue;                   \
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

void logic(ll n, vll &vec1, vll &vec2)
{
    ll lowLim = 1;
    ll gcdVal = 0;
    ll output = 1;
    for (ll i = 0; i < n; i++)
    {
        calc1;
        cond1;
        cond2;
    }
    cout << output << "\n";
}

void getInput(ll n, vll &vec1, vll &vec2)
{
    for (ll i = 0; i < n; i++)
    {
        cin >> vec1[i] >> vec2[i];
    }
}

void solve()
{
    ll n;
    cin >> n;
    vll vec1(n, 0);
    vll vec2(n, 0);
    getInput(n, vec1, vec2);
    logic(n, vec1, vec2);
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