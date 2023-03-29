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

ll N, myArr[300005];
queue<int> queuePos, queueNeg;
bool zeroFreq;

#define cond1           \
    if (zeroFreq)       \
    {                   \
        cout << "NO\n"; \
        return;         \
    }

#define cond2                    \
    if (myArr[i] == 0)           \
    {                            \
        cout << "0 ";            \
    }                            \
    if (myArr[i] > 0)            \
    {                            \
        queuePos.push(myArr[i]); \
    }                            \
    if (myArr[i] < 0)            \
    {                            \
        queueNeg.push(myArr[i]); \
    }

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

#define cond3                            \
    if (tempVar > 0)                     \
    {                                    \
        tempVar += queueNeg.front();     \
        cout << queueNeg.front() << " "; \
        queueNeg.pop();                  \
    }                                    \
    else                                 \
    {                                    \
        tempVar += queuePos.front();     \
        cout << queuePos.front() << " "; \
        queuePos.pop();                  \
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

void part1()
{
    for (int i = 1; i <= N; i++)
    {
        cond2;
    }
}

void part2()
{
    ll tempVar = 0;
    while (queueNeg.size() && queuePos.size())
    {
        cond3;
    }
}

void disp2()
{
    while (queuePos.size())
    {
        cout << queuePos.front() << " ";
        queuePos.pop();
    }
}

void getInput()
{
    for (int i = 1; i <= N; i++)
    {
        cin >> myArr[i];
        if (myArr[i] != 0)
        {
            zeroFreq = false;
        }
    }
}

void disp1()
{
    while (queueNeg.size())
    {
        cout << queueNeg.front() << " ";
        queueNeg.pop();
    }
}

void solve()
{
    zeroFreq = true;
    cin >> N;
    getInput();
    cond1;
    cout << "YES\n";
    part1();
    part2();

    disp1();
    disp2();

    cout << "\n";
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