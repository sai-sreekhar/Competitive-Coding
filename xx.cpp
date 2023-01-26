/*
    Author: Sai Sreekar
    Test Case Description:
    First line contains an integer T (between 1 and 150) which stands for the number of testcases.
    The only line of each test case contains string s.
    String contains letters from a to z(all lower cased);
*/

/*
    Logic:
    Minimum number of partitions to be made so that every partiton is palindrome.
    Sample Input:
    5
    abcd
    nitin
    abab
    abaca
    ababcb
    Sample Output:
    3
    0
    1
    2
    1
*/

#include <bits/stdc++.h>
using namespace std;

int getMinPartitions(string str)
{
    int paritions[str.length()];
    bool dp[str.length()][str.length()];
    memset(dp, false, sizeof(dp));

    for (int i = 0; i < str.length(); i++)
    {
        int minPartitions = i;
        for (int j = 0; j <= i; j++)
        {
            if (str[i] == str[j] && (i - j < 2 || dp[j + 1][i - 1]))
            {
                dp[j][i] = true;
                if (j == 0)
                {
                    minPartitions = min(minPartitions, 0);
                }
                else
                {
                    minPartitions = min(minPartitions, paritions[j - 1] + 1);
                }
            }
        }
        paritions[i] = minPartitions;
    }
    return paritions[str.length() - 1];
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        cout << getMinPartitions(str) << endl;
    }

    return 0;
}