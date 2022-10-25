#include <bits/stdc++.h>
using namespace std;
int main()
{
    int testCases;
    cin >> testCases;
    while (testCases--)
    {
        int n, m;
        cin >> n >> m;
        if (n == 1 && m == 1)
        {
            cout << 0 << "\n";
        }
        else if (n <= m)
        {
            cout << 2 * (n - 1) + m << "\n";
        }
        else
        {
            cout << 2 * (m - 1) + n << "\n";
        }
    }
    return 0;
}