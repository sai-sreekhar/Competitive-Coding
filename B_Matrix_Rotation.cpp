#include <bits/stdc++.h>

using namespace std;

void isPossible()
{
    int n1, n2, n3, n4;
    cin >> n1 >> n2;
    cin >> n3 >> n4;
    int minimumNumber = min(min(n1, n2), min(n3, n4));
    int maximumNumber = max(max(n1, n2), max(n3, n4));
    if ((minimumNumber == n1 && maximumNumber == n4) || (minimumNumber == n4 && maximumNumber == n1) || (minimumNumber == n3 && maximumNumber == n2) || (minimumNumber == n2 && maximumNumber == n3))
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
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