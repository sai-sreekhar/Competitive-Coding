// /*
//     Author: Sai Sreekar
//     Created: 2023/02/16 20:22:36
//     Last Modified: 2023/02/17 02:39:38
// */

// #include <bits/stdc++.h>

// using namespace std;

// // typedefs
// typedef long long int ll;
// typedef unsigned long long int ull;
// typedef long double lld;
// typedef vector<ll> vll;
// typedef vector<pair<ll, ll>> vpll;
// typedef pair<ll, ll> pll;

// // Debug Utils
// #ifndef ONLINE_JUDGE
// #define debug(x...)               \
//     cerr << "[" << #x << "] = ["; \
//     _print(x)
// #else
// #define debug(x...)
// #endif

// void __print(int x)
// {
//     cerr << x;
// }
// void __print(long x) { cerr << x; }
// void __print(long long x) { cerr << x; }
// void __print(unsigned x) { cerr << x; }
// void __print(unsigned long x) { cerr << x; }
// void __print(unsigned long long x) { cerr << x; }
// void __print(float x) { cerr << x; }
// void __print(double x) { cerr << x; }
// void __print(long double x) { cerr << x; }
// void __print(char x) { cerr << '\'' << x << '\''; }
// void __print(const char *x) { cerr << '"' << x << '"'; }
// void __print(const string &x) { cerr << '"' << x << '"'; }
// void __print(bool x) { cerr << (x ? "true" : "false"); }

// template <typename T, typename V>
// void __print(const pair<T, V> &x)
// {
//     cerr << '{';
//     __print(x.first);
//     cerr << ',';
//     __print(x.second);
//     cerr << '}';
// }
// template <typename T>
// void __print(const T &x)
// {
//     int f = 0;
//     cerr << '{';
//     for (auto &i : x)
//         cerr << (f++ ? "," : ""), __print(i);
//     cerr << "}";
// }
// void _print() { cerr << "]\n"; }
// template <typename T, typename... V>
// void _print(T t, V... v)
// {
//     __print(t);
//     if (sizeof...(v))
//         cerr << ", ";
//     _print(v...);
// }

// template <typename... Params>
// void _print(priority_queue<Params...> q)
// {
//     while (!q.empty())
//     {
//         cerr << " " << q.top() << ",";
//         q.pop();
//     }
//     cerr << "]" << endl;
// }

// // Operator Overloads
// template <typename T1, typename T2>
// istream &operator>>(istream &istream, pair<T1, T2> &p) { return (istream >> p.first >> p.second); }
// template <typename T>
// istream &operator>>(istream &istream, vector<T> &v)
// {
//     for (auto &it : v)
//         cin >> it;
//     return istream;
// }
// template <typename T1, typename T2>
// ostream &operator<<(ostream &ostream, const pair<T1, T2> &p) { return (ostream << p.first << " " << p.second << "\n"); }
// template <typename T>
// ostream &operator<<(ostream &ostream, const vector<T> &c)
// {
//     for (auto &it : c)
//         cout << it << " ";
//     return ostream;
// }

// pair<ll, ll> logic(ll n, ll k)
// {
//     ll s = 0, e = 0;
//     for (ll i = 0; i < n; i++)
//     {
//         ll first, second;
//         cin >> first >> second;
//         if (first == k)
//         {
//             s++;
//         }

//         if (second == k)
//         {
//             e++;
//         }
//     }

//     return {s, e};
// }
// void solve()
// {
//     ll n, k;
//     cin >> n >> k;

//     pll p = logic(n, k);
//     debug(p);
//     if (p.first > 0 && p.second > 0)
//     {
//         cout << "YES" << endl;
//         return;
//     }

//     cout << "NO" << endl;
// }

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);

//     // #ifndef ONLINE_JUDGE
//     // freopen("in.txt","r", stdin);
//     // freopen("out.txt", "w", stdout);
//     // #endif

//     int t = 1;
//     cin >> t;
//     for (int i = 1; i <= t; i++)
//     {
// #ifndef ONLINE_JUDGE
//         cerr << "\nTest Case #" << i << ":"
//              << "\n";
// #endif
//         solve();
//     }

// #ifndef ONLINE_JUDGE
//     cerr << "\nTime Taken: " << (float)clock() / CLOCKS_PER_SEC << " sec"
//          << "\n";
// #endif

//     return 0;
// }

// Header Files
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <unordered_set>
#include <list>
#include <iterator>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <bitset>
#include <random>
#include <map>
#include <unordered_map>
#include <stdio.h>
#include <complex>
#include <math.h>
#include <cstring>
#include <chrono>
#include <string>
#include <climits>
// Header Files End

using namespace std;
#define pb push_back
#define ppb pop_back
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define ll long long
#define m(x, y) map<x, y>
#define um(x, y) unordered_map<x, y>
#define vll vector<long long>
#define vvll vector<vector<ll>>
// #define f(i, n) for (ll i = 0; i < n; i++)
#define endl "\n"
#define nline cout << endl;
#define yyes cout << "YES"
#define nno cout << "NO"
#define debug(v)          \
    cout << "V [ ";       \
    for (auto i : v)      \
        cout << i << " "; \
    cout << "]" << endl;
#define debugm(v)    \
    for (auto i : v) \
        cout << i.first << " " << i.second << endl;
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
const int M = 1e9 + 7;
ll maxx = LLONG_MAX;
ll minn = LLONG_MIN;

void if_only_i_was_good()
{
    ll n, k;
    cin >> n >> k;
    m(ll, ll) m;
    for (int i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;

        if (k >= a && k <= b)
        {
            // cout << "ni";
            for (int j = a; j <= b; j++)
            {
                m[j]++;
            }
        }
    }
    if (m.size() == 0)
    {
        nno;
        return;
    }
    ll maxi = 0;
    ll maxVal = 0;
    for (auto i : m)
    {
        // cout << i.first << " " << i.second << endl;
        if (i.second > maxi)
        {
            // cout << i.second << " " << maxi << endl;
            maxi = i.second;
        }
    }
    // cout << maxi << endl;
    for (auto i : m)
    {
        if (i.second == maxi && i.first != k)
        {

            nno;
            return;
        }
    }
    yyes;
}

int main()
{
    fast;
    int t = 1;
    cin >> t;
    while (t--)
    {
        if_only_i_was_good();

        nline;
    }
    return 0;
}