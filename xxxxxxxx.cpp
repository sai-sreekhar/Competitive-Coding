/*
    Author: Sai Sreekar
    Test Case Description:
    First line contains an integer T (between 1 and 150) which stands for the number of testcases.
    Each test case consists 2 lines.
    The first line consists of integer n.
    The second line consists of n numbers.
*/

/*
    Logic:
    Sample Input:
    2
    4
    64 646 56 46
    3
    9 99 1
    Sample Output:
    646645646
    9991
*/

#include <bits/stdc++.h>

using namespace std;

#define ll long long

using namespace std;

int myCompare(string A, string B)
{
    string AB = A.append(B);
    string BA = B.append(A);
    return AB.compare(BA) > 0 ? 1 : 0;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end(), myCompare);
        for (int i = 0; i < arr.size(); i++)
        {
            cout << arr[i];
        }
        cout << "\n";
    }
}