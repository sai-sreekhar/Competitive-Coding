/*
    Author: Sai Sreekar
    Test Case Description:
    First line contains an integer T (between 1 and 150) which stands for the number of testcases.
    Each test case consists of sigle integer n
*/

/*
    Logic:
    Sequence 1,1,2,1,2,3,1,2,3,4,1,2,3,4,5.........

    Sample Input:
    4
    3
    55
    56
    1

    Sample Output:
    2
    10
    1
    1
*/

#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main()
{
    ll testCases;
    cin >> testCases;
    while (testCases--)
    {
        ll n;
        cin >> n;
        n--;
        for (ll i = 1; i <= n; i++)
        {
            n -= i;
        }
        cout << n + 1 << "\n";
    }
    return 0;
}
