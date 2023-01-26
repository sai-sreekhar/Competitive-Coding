/*
    Author: Sai Sreekar
    Test Case Description:
    First line contains an integer T (between 1 and 150) which stands for the number of testcases.
    The first line of each test case contains a single integer n(2 <= n <= 1000>
    The second line of each test case contains n integers p1,p2,…,pn (1≤pi≤n). 1≤ pi ≤ 10^6 (all are distinct)
*/

/*
    Logic:
    Minimum number of swaps to sort the array. (Logic - Using Graphs)
    For every cycle we need cycleSize -1 swaps and we sum up (cycleSize-1) for all cycles formed.
    Sample Input:
    5
    5
    9 10 6 3 7
    4
    1 2 3 4
    5
    1 5 2 4 3
    5
    5 4 3 2 1
    4
    9 1 4 3
    Sample Output:
    3
    0
    2
    2
    2
*/

#include <bits/stdc++.h>

using namespace std;

#define ll long long

void minSwaps()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    vector<bool> isVisited(n, false);
    vector<pair<int, int>> vec(n);

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    for (int i = 0; i < n; i++)
    {
        vec[i].first = nums[i];
        vec[i].second = i;
    }

    sort(vec.begin(), vec.end());
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (isVisited[i] or vec[i].second == i)
        {
            continue;
        }

        int cycleSize = 0; // require cycle-1 swaps
        int j = i;

        while (!isVisited[j])
        {
            isVisited[j] = true;
            j = vec[j].second;
            cycleSize++;
        }

        if (cycleSize > 1) // if cycle
        {
            ans += cycleSize - 1;
        }
        else
        {
            ans = 0;
        }
    }

    cout << ans << "\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        minSwaps();
    }
    return 0;
}