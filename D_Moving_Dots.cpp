// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// #define rep(i, a, b) for (int i = (a); i < (b); i++)
// const int M = 1e9 + 7;
// int32_t main()
// {
//     int n;
//     cin >> n;
//     vector<int> pw(n + 1, 1), a(n + 1);
//     rep(i, 1, n + 1) pw[i] = pw[i - 1] * 2 % M;
//     rep(i, 1, n + 1) cin >> a[i];
//     int ans = 0;

//     rep(i, 1, n + 1)
//     {
//         rep(j, i + 1, n + 1)
//         {
//             int x = a[j] - a[i];
//             int l = 1, r = i - 1;
//             int t = 1;
//             while (l < r + 1)
//             {
//                 int m = (l + r) >> 1;
//                 if (a[i] - a[m] <= x)
//                     r = m - 1;
//                 else
//                     l = m + 1;
//             }
//             t = (t * pw[r]) % M;
//             l = j + 1, r = n;
//             while (l < r + 1)
//             {
//                 int m = (l + r) >> 1;
//                 if (a[m] - a[j] < x)
//                     l = m + 1;
//                 else
//                     r = m - 1;
//             }
//             t = (t * pw[n - l + 1]) % M;
//             ans = (ans + t) % M;
//         }
//     }
//     cout << ans << '\n';
//     return 0;
// }

/*
    Author: Sai Sreekar
    Created: 2023/02/09 21:49:52
    Last Modified: 2023/02/09 22:04:02
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
#define debug(var1...)               \
    cerr << "[" << #var1 << "] = ["; \
    _print(var1)
#else
#define debug(var1...)
#endif

void __print(int var1)
{
    cerr << var1;
}
void __print(long var1) { cerr << var1; }
void __print(long long var1) { cerr << var1; }
void __print(unsigned var1) { cerr << var1; }
void __print(unsigned long var1) { cerr << var1; }
void __print(unsigned long long var1) { cerr << var1; }
void __print(float var1) { cerr << var1; }
void __print(double var1) { cerr << var1; }
void __print(long double var1) { cerr << var1; }
void __print(char var1) { cerr << '\'' << var1 << '\''; }
void __print(const char *var1) { cerr << '"' << var1 << '"'; }
void __print(const string &var1) { cerr << '"' << var1 << '"'; }
void __print(bool var1) { cerr << (var1 ? "true" : "false"); }

template <typename T, typename V>
void __print(const pair<T, V> &var1)
{
    cerr << '{';
    __print(var1.first);
    cerr << ',';
    __print(var1.second);
    cerr << '}';
}
template <typename T>
void __print(const T &var1)
{
    int f = 0;
    cerr << '{';
    for (auto &i : var1)
        cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T temp, V... v)
{
    __print(temp);
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
#define int long long
const int M = 1e9 + 7;
#define res1 (res + (temp * power[n - left + 1]) % M) % M;
#define cond1 (vec[i] - vec[((left + right) >> 1)] <= var1)
#define cond2 (vec[((left + right) >> 1)] - vec[j] < var1)
#define r ((left + right) >> 1) - 1
#define l ((left + right) >> 1) + 1
#define t (temp * power[right]) % M;

void fillPow(vector<int> &power, int n)
{
    power[0] = 1;
    for (int i = 1; i < power.size(); i++)
    {
        power[i] = (power[i - 1] * 2) % M;
    }
}

void logic(vector<int> &vec, vector<int> &power, int n)
{
    int res = 0;
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = i + 1; j < n + 1; j++)
        {
            int var1 = vec[j] - vec[i];
            int left = 1;
            int right = i - 1;
            int temp = 1;
            while (left < right + 1)
            {
                if (cond1)
                {
                    right = r;
                }
                else
                {
                    left = l;
                }
            }

            temp = t;
            left = j + 1, right = n;
            while (left < right + 1)
            {
                if (cond2)
                {
                    left = l;
                }
                else
                {
                    right = r;
                }
            }
            res = res1;
        }
    }

    cout << res << "\n";
}

void solve()
{
    int n;
    cin >> n;
    vector<int> power(n + 1, 1), vec(n + 1);

    for (int i = 1; i < n + 1; i++)
    {
        cin >> vec[i];
    }
    fillPow(power, n);

    int res = 0;
    logic(vec, power, n);
    return;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // #ifndef ONLINE_JUDGE
    // freopen("in.txt","right", stdin);
    // freopen("out.txt", "w", stdout);
    // #endif

    int temp = 1;
    // cin >> temp;
    for (int i = 1; i <= temp; i++)
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