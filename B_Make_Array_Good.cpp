#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define ONLINE_JUDGE
#define DEBUG_CODE


void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> vec;
    for (int i = 0; i < n; ++i)
    {
        int num;
        cin >> num;
        vec.push_back({num, i + 1});
    }
    sort(vec.begin(), vec.end());
    cout << n - 1 << endl;
    for (int i = 1; i < n; ++i)
    {
        
        int p = (vec[i][0]) % vec[i - 1][0];
        if (p == 0)
        {
            cout << vec[i][1] << " " << 0 << endl;
            continue;
        }
        
        vec[i][0] = vec[i][0] + vec[i - 1][0] - p;
        cout << vec[i][1] << " " << vec[i - 1][0] - p << endl;
    }
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