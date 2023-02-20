/*
    Author: Sai Sreekar
    Created: 2023/02/05 17:36:35
    Last Modified: 2023/02/05 18:03:45
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

void solve()
{
    int n;
    cin >> n;
    int sum = 0;
    int i = 1;
    int aliceWhite = 0;
    int bobWhite = 0;
    int aliceBlack = 0;
    int bobBlack = 0;

    if (n == 1)
    {
        cout << 1 << " " << 0 << " " << 0 << " " << 0 << "\n";
        return;
    }

    aliceWhite += 1;
    sum += 1;
    int j = 1;
    while (sum < n)
    {
        debug(aliceWhite, bobWhite, i, j);
        if (i % 2 == 0)
        {
            int requiredcards1 = j + 1;
            int requiredcards2 = j + 2;
            if (sum + requiredcards1 <= n)
            {
                aliceWhite += (requiredcards1 / 2);
                aliceBlack += (requiredcards1 / 2);
                if (requiredcards1 % 2 != 0)
                {
                    aliceWhite += 1;
                }
                sum += requiredcards1;
            }
            else
            {
                aliceWhite += ((n - sum) / 2);
                aliceBlack += ((n - sum) / 2);
                if ((n - sum) % 2 != 0)
                {
                    aliceWhite += 1;
                }
                sum += (n - sum);
                break;
            }

            if (sum + requiredcards2 <= n)
            {
                aliceWhite += (requiredcards2 / 2);
                aliceBlack += (requiredcards2 / 2);
                if (requiredcards2 % 2 != 0)
                {
                    aliceWhite += 1;
                }
                sum += requiredcards2;
            }
            else
            {
                aliceWhite += ((n - sum) / 2);
                aliceBlack += ((n - sum) / 2);
                if ((n - sum) % 2 != 0)
                {
                    aliceWhite += 1;
                }
                sum += (n - sum);
                break;
            }

            i++;
            j = j + 2;
        }
        else
        {
            int requiredcards1 = j + 1;
            int requiredcards2 = j + 2;

            if (sum + requiredcards1 <= n)
            {
                bobWhite += (requiredcards1 / 2);
                bobBlack += (requiredcards1 / 2);
                if (requiredcards1 % 2 != 0)
                {
                    bobBlack += 1;
                }
                sum += requiredcards1;
            }
            else
            {
                bobWhite += ((n - sum) / 2);
                bobBlack += ((n - sum) / 2);
                if ((n - sum) % 2 != 0)
                {
                    bobBlack += 1;
                }
                sum += (n - sum);
                break;
            }

            if (sum + requiredcards2 <= n)
            {
                bobWhite += (requiredcards2 / 2);
                bobBlack += (requiredcards2 / 2);
                if (requiredcards2 % 2 != 0)
                {
                    bobBlack += 1;
                }
                sum += requiredcards2;
            }
            else
            {
                bobWhite += ((n - sum) / 2);
                bobBlack += ((n - sum) / 2);
                if ((n - sum) % 2 != 0)
                {
                    bobBlack += 1;
                }
                sum += (n - sum);
                break;
            }

            i++;
            j = j + 2;
        }
    }

    cout << aliceWhite << " " << aliceBlack << " " << bobWhite << " " << bobBlack << "\n";
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
}