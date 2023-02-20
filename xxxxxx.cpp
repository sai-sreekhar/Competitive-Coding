/*
    Author: Sai Sreekar
    Test Case Description:
    First line contains an integer T (between 1 and 150) which stands for the number of testcases.
    Each test case consists of a string of size 2
*/

/*
    Logic:
    No of valid moves for king in chessboard

    Sample Input:
    3
    a1
    a7
    d5

    Sample Output:
    3
    5
    8
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
        string s;
        cin >> s;
        if (s == "a1" || s == "a8" || s == "h1" || s == "h8")
        {
            cout << 3 << "\n";
        }
        else if (s[0] == 'a' || s[0] == 'h' || s[1] == '1' || s[1] == '8')
        {
            cout << 5 << "\n";
        }
        else
        {
            cout << 8 << "\n";
        }
    }
    return 0;
}
