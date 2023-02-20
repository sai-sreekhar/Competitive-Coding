/*
    Author: Sai Sreekar
    Created: 2018/02/04 12:24:41
    Last modified: 2023/02/04 00:25:35
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

int digit_sum(int n)
{
    int ret = 0;
    while (n)
    {
        ret += n % 10;
        n /= 10;
    }
    return ret;
}
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    set<int> s;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        if (a[i] > 9)
        {
            s.insert(i);
        }
    }
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int l, r;
            cin >> l >> r;
            --l, --r;
            int lst = l;
            while (!s.empty())
            {
                auto it = s.lower_bound(lst);
                if (it == s.end() || *it > r)
                {
                    break;
                }
                a[*it] = digit_sum(a[*it]);
                int paiu = *it;
                s.erase(it);
                if (a[paiu] > 9)
                {
                    s.insert(paiu);
                }
                lst = paiu + 1;
            }
        }
        else
        {
            int x;
            cin >> x;
            --x;
            cout << a[x] << "\n";
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}