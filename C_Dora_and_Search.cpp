/*
    Author: Sai Sreekar
    Created: 2023/02/12 14:53:27
    Last Modified: 2023/02/12 15:58:24
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
    for (auto &left : x)
        cerr << (f++ ? "," : ""), __print(left);
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

#define cd1                     \
    if (arr[left] == mini)      \
    {                           \
        left++;                 \
        mini++;                 \
    }                           \
    else if (arr[left] == maxi) \
    {                           \
        left++;                 \
        maxi--;                 \
    }

#define cd2                      \
    if (arr[right] == mini)      \
    {                            \
        right--;                 \
        mini++;                  \
    }                            \
    else if (arr[right] == maxi) \
    {                            \
        right--;                 \
        maxi--;                  \
    }

bool logic(vll &arr, ll &n)
{
    ll mini = 1;
    ll maxi = n;
    ll left = 0;
    ll right = n - 1;
    ll prevleft, prevRight;
    while (left < right)
    {
        prevleft = left;
        prevRight = right;
        cd1;
        cd2;

        if (prevleft == left and prevRight == right)
        {
            cout << left + 1 << " " << right + 1 << '\n';
            return true;
        }
    }

    return false;
}

void solve()
{
    ll n;
    cin >> n;
    vll arr(n);
    cin >> arr;
    bool flag = logic(arr, n);
    if (!flag)
    {
        cout << -1 << '\n';
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // #ifndef ONLINE_JUDGE
    // freopen("in.txt","right", stdin);
    // freopen("out.txt", "w", stdout);
    // #endif

    int t = 1;
    cin >> t;
    for (int left = 1; left <= t; left++)
    {
#ifndef ONLINE_JUDGE
        cerr << "\nTest Case #" << left << ":"
             << "\n";
#endif
        solve();
    }

#ifndef ONLINE_JUDGE
    cerr << "\nTime Taken: " << (float)clock() / CLOCKS_PER_SEC << " sec"
         << "\n";
#endif
}