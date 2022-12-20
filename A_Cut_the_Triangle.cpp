#include <bits/stdc++.h>

using namespace std;
#define ll long long int

void isPossible()
{
    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    if ((x1 == x2 || x2 == x3 || x3 == x1) && (y1 == y2 || y2 == y3 || y3 == y1))
    {
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n";
    }
}

int main()
{
    int testCases;
    cin >> testCases;
    while (testCases--)
    {
        isPossible();
    }
    return 0;
}