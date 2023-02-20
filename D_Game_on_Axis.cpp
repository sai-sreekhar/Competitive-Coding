#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ONLINE_JUDGE
#define DEBUG_CODE

#ifdef DEBUG_CODE
#define TRACE(msg, ...) printTrace(__LINE__, __FILE__, msg, __VA_ARGS__)
#define PRINT_ARRAY(arr, n, type) myPrint<type>(arr, n)
#else
#define TRACE(msg, ...)
#define PRINT_ARRAY(arr, n, type)
#endif

template <typename T1>
void myPrint(T1 *arr, int n)
{
    cout << "myPrint Function output is: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void printTrace(int line, const char *fileName, const char *msg, ...)
{
    va_list args;
    char buffer[1024 + 2] = {0};
    snprintf(buffer, sizeof(buffer), "%s(%d) : ", fileName, line);
    int stringLength = strnlen(buffer, 1024);
    int remainingBufferSize = 1024 - stringLength;
    va_start(args, msg);
    vsnprintf(buffer + stringLength, remainingBufferSize, msg, args);
    va_end(args);
    cout << buffer << "\n"
         << flush;
}

ll c = 0;
bool dfs(vector<vector<ll>> adjList, ll node, vector<bool> visited)
{
    visited[node] = true;
    for (ll i = 0; i < adjList[node].size(); i++)
    {
        if (!visited[adjList[node][i]])
        {
            c++;
            dfs(adjList, adjList[node][i], visited);
        }
        else
        {
            return false;
        }
    }
    return true;
}

void dfs2(vector<vector<ll>> adjList, ll node, vector<bool> visited, int n)
{
    if (visited[node] == true)
    {
        c++;
        return;
    }

    visited[node] = true;

    if (adjList[node].size() == 0)
    {
        return;
    }

    dfs2(adjList, adjList[node][0], visited, n);
}

void solve()
{
    ll n;
    cin >> n;
    vector<ll> vec(n + 1);
    for (ll i = 1; i <= n; i++)
    {
        cin >> vec[i];
    }

    vector<vector<ll>> adjList(n + 1);
    for (ll i = 1; i <= n; i++)
    {
        if (i + vec[i] >= 1 && i + vec[i] <= n)
        {
            adjList[i].push_back(i + vec[i]);
        }
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     cout << i << " -> ";
    //     for (int j = 0; j < adjList[i].size(); j++)
    //     {
    //         cout << adjList[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    vector<bool> visited(n + 1, false);
    bool flag = dfs(adjList, 1, visited);
    ll res = 0;
    // cout << c << "\n";
    if (flag != 0)
    {
        res += ((n - c - 1) * (2 * n + 1));
    }
    // cout << res << "\n";

    ll k = (c + 1);
    c = 0;
    for (ll i = 1; i <= k; i++)
    {
        for (ll j = 1; j <= n; j++)
        {
            vector<bool> visited(n + 1, false);
            visited[i] = true;
            dfs2(adjList, j, visited, n);
            // cout << "c: " << c << "\n";
        }
        // cout << "c: " << c << "\n";
        res += ((2 * n + 1) - c);
        c = 0;
    }
    cout << res << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}