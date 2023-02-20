/*
    Author: Sai Sreekar
    Created:
    Last Modified:
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
#define debug(s...)               \
    cerr << "[" << #s << "] = ["; \
    _print(s)
#else
#define debug(s...)
#endif

void __print(int s)
{
    cerr << s;
}
void __print(long s) { cerr << s; }
void __print(long long s) { cerr << s; }
void __print(unsigned s) { cerr << s; }
void __print(unsigned long s) { cerr << s; }
void __print(unsigned long long s) { cerr << s; }
void __print(float s) { cerr << s; }
void __print(double s) { cerr << s; }
void __print(long double s) { cerr << s; }
void __print(char s) { cerr << '\'' << s << '\''; }
void __print(const char *s) { cerr << '"' << s << '"'; }
void __print(const string &s) { cerr << '"' << s << '"'; }
void __print(bool s) { cerr << (s ? "true" : "false"); }

template <typename T, typename V>
void __print(const pair<T, V> &s)
{
    cerr << '{';
    __print(s.first);
    cerr << ',';
    __print(s.second);
    cerr << '}';
}
template <typename T>
void __print(const T &s)
{
    int f = 0;
    cerr << '{';
    for (auto &i : s)
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

void solve()
{
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        if ((s[s.size() - 1] == '+') || (s[0] == '+'))
        {
            ans++;
        }
        else
        {
            ans--;
        }
    }
    cout << ans << "\n";
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
    // cin >> t;
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
}