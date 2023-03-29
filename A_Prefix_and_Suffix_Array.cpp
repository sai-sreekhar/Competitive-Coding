/*
    Author: Sai Sreekar
    Created: 2023/03/04 21:48:26
    Last Modified: 2023/03/05 18:36:47
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
    for (auto &i : x)
        cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T str1, V... v)
{
    __print(str1);
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

#define l1                                \
    for (int i = 0; i < 2 * (n - 1); i++) \
    {                                     \
        if (vec[i].size() == n - 1)       \
        {                                 \
            strVec.push_back(vec[i]);     \
        }                                 \
    }

#define l2                                                 \
    if (strVec[0].substr(1) != strVec[1].substr(0, n - 2)) \
    {                                                      \
        swap(strVec[0], strVec[1]);                        \
    }

bool isPalindrome(string S)
{
    string P = S;
    reverse(P.begin(), P.end());
    if (S == P)
    {
        return true;
    }

    return false;
}

void solve()
{
    int n;
    cin >> n;
    vector<string> vec(2 * n - 2);
    cin >> vec;

    vector<string> strVec;
    for (int i = 0; i < 2 * (n - 1); i++)
    {
        if (vec[i].size() == n - 1)
        {
            strVec.push_back(vec[i]);
        }
    }
    if (strVec[0].substr(1) != strVec[1].substr(0, n - 2))
    {
        swap(strVec[0], strVec[1]);
    }
    string str1 = strVec[0] + strVec[1][n - 2];
    string str2 = str1;
    reverse(str2.begin(), str2.end());
    if (str1 == str2)
    {
        cout << "YES"
             << "\n";
        return;
    }

    cout << "NO"
         << "\n";
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

    int str1 = 1;
    cin >> str1;
    for (int i = 1; i <= str1; i++)
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