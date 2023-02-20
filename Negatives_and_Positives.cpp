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
void _print(T t, V... vec)
{
    __print(t);
    if (sizeof...(vec))
        cerr << ", ";
    _print(vec...);
}

#ifndef ONLINE_JUDGE
#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define debug(x...)
#endif

void solve()
{
    // int n;
    // cin >> n;
    // vector<int> a(n);
    // int sum = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> a[i];
    //     sum += a[i];
    // }

    // int toAdd1 = 0;
    // for (int i = 0; (i + 1) <= n - 1; i += 2)
    // {
    //     if ((-1 * a[i]) + (-1 * a[i + 1]) > 0)
    //     {
    //         toAdd1 += (-1 * a[i] + -1 * a[i + 1]);
    //         // a[i + 1] += (-1 * a[i] + -1 * a[i + 1]);
    //     }
    //     if (a[i + 1] == 0)
    //     {
    //         if (i + 2 < n)
    //         {
    //             if (a[i + 2] < 0)
    //             {
    //                 toAdd1 += (-1 * a[i + 2]);
    //                 // a[i+2] = 0;
    //             }
    //         }
    //     }
    // }

    // int toAdd2 = 0;
    // for (int i = 1; (i + 1) < n; i += 2)
    // {
    //     if ((-1 * a[i]) + (-1 * a[i + 1]) > 0)
    //     {
    //         toAdd2 += (-1 * a[i] + -1 * a[i + 1]);
    //         // a[i + 1] += (a[i] + a[i + 1]);
    //     }
    //     if (a[i + 1] == 0)
    //     {
    //         if (i + 2 < n)
    //         {
    //             if (a[i + 2] < 0)
    //             {
    //                 toAdd2 += (-1 * a[i + 2]);
    //                 // a[i+2] = 0;
    //             }
    //         }
    //     }
    // }

    // // debug(sum, toAdd1, toAdd2);
    // cout << (sum + (2 * max(toAdd1, toAdd2))) << "\n";

    ll n;
    cin >> n;
    vector<ll> vec(n);

    ll sum = 0;
    ll count = 0;

    for (ll i = 0; i < n; i++)
    {
        cin >> vec[i];
        sum += abs(vec[i]);
        if (vec[i] < 0)
        {
            count++;
            vec[i] = abs(vec[i]);
        }
    }

    if (count % 2 == 0)
    {
        cout << sum << "\n";
        return;
    }

    cout << sum - 2 * (*min_element(vec.begin(), vec.end())) << "\n";
    return;
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

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
#ifndef ONLINE_JUDGE
        cout << "Test Case #" << i << ":"
             << "\n";
#endif
        solve();
    }

#ifndef ONLINE_JUDGE
    cerr << "Time Taken: " << (float)clock() / CLOCKS_PER_SEC << " sec"
        << "\n";
#endif
}
