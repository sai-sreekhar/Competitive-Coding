#include <bits/stdc++.h>
 
using namespace std;
 
#define ONLINE_JUDGE
 
#define ll long long
 
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
        int m = 8;
        int n = 8;
        string arr[m];
        for (int i = 0; i < m; i++)
        {
            cin >> arr[i];
        }
 
        int flag = 0;
        for (int i = 0; i < m; i++)
        {
            bool found = false;
            if (arr[i] == "RRRRRRRR")
            {
                found = true;
                flag = 1;
                break;
            }
        }
 
        if (flag == 0)
        {
            cout << "B\n";
        }
        else
        {
            cout << "R\n";
        }
    }
 
    return 0;
}
