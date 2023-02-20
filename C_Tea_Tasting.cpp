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
    int temp = 0;
    cerr << '{';
    for (auto &i : x)
        cerr << (temp++ ? "," : ""), __print(i);
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

#define ml                                                                     \
    ll ind = lower_bound(v.begin(), v.end(), ((a[i] + v[i - 1]))) - v.begin(); \
    if (ind >= i)                                                              \
    {                                                                          \
        temp[ind - 1]++;                                                       \
        temp[i - 1]--;                                                         \
        res[ind] += (((a[i] + v[i - 1])) - v[ind - 1]);                        \
    }                                                                          \
    else                                                                       \
    {                                                                          \
        res[i] += (((a[i] + v[i - 1])) - v[i - 1]);                            \
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
ostream &operator<<(ostream &ostream, const vector<T> &res)
{
    for (auto &it : res)
        cout << it << " ";
    return ostream;
}

// void logic(vll &a, vll &b, vll &res, ll n)
// {
//     for (ll i = 0; i < n; i++)
//     {
//         ll left = i;
//         ll right = n - 1;

//         while (true)
//         {
//             // if (a[i] <= b[i])
//             // {
//             //     res[left] = res[left] + a[i];
//             //     a[i] = 0;
//             // }
//             // else
//             // {
//             //     res[left] = res[left] + b[left];
//             //     a[i] = a[i] - b[left];
//             // }

//             cd1
//                 cd2
//                     left++;
//             if (a[i] == 0 || left > right)
//             {
//                 break;
//             }
//         }
//     }
// }

void logic(vll &temp, vll &res, vll &a, vll v, ll n)
{
    for (ll i = 1; i <= n; i++)
    {

        if ((a[i] + v[i - 1]) >= v[n])
        {
            temp[i - 1]--;
            temp[n]++;
        }
        else
        {
            ml
        }
    }

    for (ll i = n - 1; i >= 0; i--)
    {
        temp[i] += temp[i + 1];
    }
}

void func1(vll &a, vll &v, vll &c, ll n)
{
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    for (ll i = 1; i <= n; i++)
    {
        cin >> v[i];
    }

    for (ll i = 1; i <= n; i++)
    {
        c[i] = v[i];
        v[i] += v[i - 1];
    }
}

void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n + 1), v(n + 1), c(n + 1);
    vector<ll> temp(n + 1), res(n + 1, 0);

    func1(a, v, c, n);
    logic(temp, res, a, v, n);

    for (ll i = 1; i <= n; i++)
    {
        res[i] += (c[i] * temp[i]);
        cout << res[i] << " ";
    }

    cout << endl;
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