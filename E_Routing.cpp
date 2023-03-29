#include <bits/stdc++.h>
#define ld long double
#define ll long long int
#define mod 998244353
using namespace std;
int n, m;
int p[21][1 << 20];
vector<int> g[200007];
char s[1000007];

void bfs(int x)
{
    queue<int> q;
    q.push(x);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto &i : g[u])
        {
            if (!p[x][i])
            {
                p[x][i] = u;
                q.push(i);
            }
        }
    }
}
signed main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int i = 0; i < n; i++)
        bfs(i);

    for (int i = 0; i < (1 << n); i++)
    {
        bool flag = true;
        for (int j = 0; j < n; j++)
        {
            if ((i & (1 << j)) && (p[j][(i ^ (1 << j))] != (i ^ (1 << j))))
                flag = false;
        }
        if (flag)
        {
            puts("Yes");
            for (int j = 0; j < n; j++)
            {
                cout << (p[j][(i ^ (1 << j))] + 1) << " ";
            }
            return 0;
        }
    }

    puts("No");
    return 0;
}
