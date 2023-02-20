#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define lowbit(x) (x & (-x))
#define ull unsigned long long
#define pii pair<int, int>
using namespace std;
const string yes = "Yes\n", no = "No\n";
const int N = 1000005, inf = 2e18, mod = 1000000007;
int n;

struct node
{
    int idx, x, idy, y;
};
vector<node> ans;
vector<int> vis[205][205];

void add(int id, char x, char y)
{
    if (vis[y][x].size())
    {
        ans.push_back({id, x, vis[y][x].back(), y});
        vis[y][x].pop_back();
    }
    else
    {
        vis[x][y].push_back(id);
    }
}

void solve()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        if (s == "inw")
            continue;
        if (s == "iii")
        {
            add(i, 'i', 'n');
            add(i, 'i', 'w');
        }
        else if (s == "nnn")
        {
            add(i, 'n', 'i');
            add(i, 'n', 'w');
        }
        else if (s == "www")
        {
            add(i, 'w', 'i');
            add(i, 'w', 'n');
        }
        else if (s == "iin")
        {
            add(i, 'i', 'w');
        }
        else if (s == "iiw")
        {
            add(i, 'i', 'n');
        }
        else if (s == "inn")
        {
            add(i, 'n', 'w');
        }
        else if (s == "nnw")
        {
            add(i, 'n', 'i');
        }
        else if (s == "iww")
        {
            add(i, 'w', 'n');
        }
        else if (s == "nww")
        {
            add(i, 'w', 'i');
        }
    }
    while (vis['w']['n'].size())
    {
        int x = vis['w']['n'].back();
        int y = vis['n']['i'].back();
        int z = vis['i']['w'].back();
        ans.push_back({x, 'w', y, 'n'});
        ans.push_back({y, 'w', z, 'i'});
        vis['w']['n'].pop_back();
        vis['n']['i'].pop_back();
        vis['i']['w'].pop_back();
    }
    while (vis['w']['i'].size())
    {
        int x = vis['w']['i'].back();
        int y = vis['i']['n'].back();
        int z = vis['n']['w'].back();
        ans.push_back({x, 'w', y, 'i'});
        ans.push_back({y, 'w', z, 'n'});
        vis['w']['i'].pop_back();
        vis['i']['n'].pop_back();
        vis['n']['w'].pop_back();
    }
    cout << ans.size() << endl;
    for (auto [q, w, e, r] : ans)
    {
        cout << q << " " << (char)w << " " << e << " " << (char)r << endl;
    }
    ans.clear();
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}