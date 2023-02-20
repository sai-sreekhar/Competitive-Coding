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

void noOfSubstrings(string a, string b)
{
    int n = a.length();
    int m = b.length();
    int dp[n + 1][m + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << endl;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    string s, t;
    cin >> s >> t;
    vector<char> v;
    map<char, int> m;
    for (int i = 0; i < n; i++)
    {
        if (m[s[i]] == 0)
        {
            m[s[i]] = 1;
            v.push_back(s[i]);
        }
    }

    int l = v.size();
    if (v.size() <= k)
    {
        cout << n * (n + 1) / 2 << "\n";
        return;
    }

    int mini = 0;
    for (int i = 0; i < (); i++)
    {
        vector<int> sel(26, 0);
        int ans = 0;
        for (int j = 0; j < l; j++)
        {
            if (i & (1 << j))
            {
                sel[v[j] - 'a'] = 1;
            }
        }

        int siz = 0;
        for (int j = 0; j < 26; j++)
        {
            siz += sel[j];
        }
        if (siz == k)
        {
            string temp = s;
            for (int j = 0; j < n; j++)
            {
                if (sel[temp[j] - 'a'])
                {
                    temp[j] = t[j];
                }
            }
            int c = 0;
            for (int j = 0; j < n; j++)
            {
                if (temp[j] == t[j])
                {
                    c++;
                }
                else
                {
                    ans += c * (c + 1) / 2;
                    c = 0;
                }
            }
            ans += c * (c + 1) / 2;
            mini = max(mini, ans);
        }
    }
    cout << mini << "\n";
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