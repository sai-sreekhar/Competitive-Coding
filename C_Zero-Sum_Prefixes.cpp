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

void solve()
{
    ll n;
    cin >> n;
    map<ll, ll> freq;
    ll a[n];
    ll maxFreq = 0, currSum = 0, ans = 0;
    bool isFirstZeroFound = 0;
    freq.clear();

    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<ll> prefix(n, 0);
    prefix[0] = a[0];
    for (ll i = 1; i < n; i++)
    {
        prefix[i] = prefix[i - 1] + a[i];
    }

    for (ll i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            if (!isFirstZeroFound)
            {
                isFirstZeroFound = 1; // set flag
                ans += freq[0];       // pvs zero count in prefix sum
            }
            else
            {
                ans += maxFreq;
            }
            maxFreq = 0;
            freq.clear();
        }

        freq[prefix[i]]++;
        maxFreq = max(maxFreq, freq[prefix[i]]);
        debug(i, ans);
    }
    debug(ans);
    if (!isFirstZeroFound)
    {
        ans += freq[0];
    }
    else
    {
        ans += maxFreq;
    }
    debug(ans);
    cout << ans << endl;
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