/*
    Author: Sai Sreekar
    Test Case Description:
    First line contains an integer T (between 1 and 150) which stands for the number of testcases.
    Each test case consists of two lines. The first line contains a single integer n  — the length of the array.
    The second line contains the elements in array a1,a2,a3,a4,...,an;
*/

/*
    Logic:
    Maximum Sum Circular Subarray

    Sample Input:
    4
    3
    -5 -4 -8
    3
    10 -2 10
    4
    1 2 3 4
    5
    -3 5 4 -2 10

    Sample Output:
    -4
    20
    10
    17
*/

#include <bits/stdc++.h>

using namespace std;

#define ll long long

int getMaxSum(vector<int> &nums)
{
    int currMax = 0, currMin = 0, sum = 0;
    int maxSum = nums[0], minSum = nums[0];

    for (int num : nums)
    {
        currMax = max(currMax, 0) + num;
        maxSum = max(maxSum, currMax);
        currMin = min(currMin, 0) + num;
        minSum = min(minSum, currMin);
        sum += num;
    }

    if (sum == minSum)
    {
        return maxSum;
    }
    else
    {
        return max(maxSum, sum - minSum);
    }
}

int main()
{
    int testCases;
    cin >> testCases;
    while (testCases--)
    {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }
        cout << getMaxSum(nums) << "\n";
    }
    return 0;
}
