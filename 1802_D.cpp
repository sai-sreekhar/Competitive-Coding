/*
    Author: Sai Sreekar
    Created: 2023/03/09 16:10:41
    Last Modified: 2023/03/09 17:21:42
*/

#include <bits/stdc++.h>

using namespace std;

//typedefs
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double lld;
typedef vector <ll> vll;
typedef vector <pair <ll, ll> > vpll;
typedef pair <ll, ll> pll;

//Debug Utils
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

#define cd2 res = min(res, abs(*curr - vec[i].first));\
                if (curr != mySet.begin())\
                {\
                    curr--;\
                    res = min(res, abs(*curr - vec[i].first));\
                }


void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '"' << x << '"';}
void __print(const string &x) {cerr << '"' << x << '"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

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

#define cd1 if (i != n - 1)\
        {\
            res = min(res, abs(maxi - vec[i].first));\
        }
#define cd3 curr--;\
                res = min(res, abs(*curr - vec[i].first));

//Operator Overloads   
template<typename T1, typename T2>
istream& operator>>(istream &istream, pair<T1, T2> &p) { return (istream >> p.first >> p.second); }
template<typename T>
istream& operator>>(istream &istream, vector<T> &v) { for (auto &it : v) cin >> it; return istream; }
template<typename T1, typename T2>
ostream& operator<<(ostream &ostream, const pair<T1, T2> &p) { return (ostream << p.first << " " << p.second << "\n"); }
template<typename T>
ostream& operator<<(ostream &ostream, const vector<T> &c) { for (auto &it : c) cout << it << " "; return ostream; }


ll logic(vll temp,vpll vec,ll n)
{
    set<ll> mySet;
    ll res = INT_MAX;
    for (ll i = 0; i < n; i++)
    {
        ll maxi = temp[i + 1];
        cd1;

        if (!mySet.empty() && maxi < vec[i].first)
        {
            auto curr = mySet.upper_bound(vec[i].first);
            if (curr != mySet.end())
            {
                cd2;
            }
            else
            {
                cd3;
            }
        }
        
        mySet.insert(vec[i].second);
    }
    
    return res;
}

bool isPrime()
{
        
}
void func(vll &temp, ll n, vpll vec)
{
    for (ll i = n - 2; i >= 0; i--)
    {
        temp[i] = max(temp[i + 1], vec[i].second);
    }
    return;
}

void solve()
{ 
    ll n;
    cin >> n;
    vpll vec(n);
    cin >> vec;
    sort(vec.begin(),vec.end());
    vll temp(n + 1, -1);
    temp[n - 1] = vec[n - 1].second;
    func(temp, n,vec);    
    cout << logic(temp,vec,n) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("in.txt","r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("err.txt","w",stderr);
    #endif

    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
#ifndef ONLINE_JUDGE
        cerr << "\nTest Case #" << i << ":" << "\n";
#endif
        solve();
    }

#ifndef ONLINE_JUDGE
    cerr << "\nTime Taken: " << (float)clock() / CLOCKS_PER_SEC << " sec"<< "\n";
#endif

    return 0;
}