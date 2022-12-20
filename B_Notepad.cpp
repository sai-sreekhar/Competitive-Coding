#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<pair<char, char>, int> mp;
    pair<char, char> pr = {s[0], s[1]};
    mp[pr]++;
    for (int i = 2; i < n; i++)
    {
        pair<char, char> c = {s[i - 1], s[i]};
        if (mp[c] != 0)
        {
            if (c == pr && mp[c] > 1 || c != pr)
            {
                cout << "YES"
                     << "\n";
                return;
            }
        }
        pr = c;
        mp[c]++;
    }
    cout << "NO"
         << "\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}