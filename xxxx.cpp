/*
    Author: Sai Sreekar
    Test Case Description:
    First line contains an integer T (between 1 and 150) which stands for the number of testcases.
    Each test case consists of two lines. The first line contains a single integer n  — the length of the string s.
    The second line contains the string s of length n consisting of lowercase English letters.
*/

/*
    Logic:
    Find a string with minimum number of operations in which all characters that are present in it appear the same number of times. If there are multiple solutions, print any.


    Sample Input:
    4
    5
    hello
    10
    saisreekar
    5
    eevee
    6
    appall


    Sample Output:
    hezlo
    saksreekar
    eeeee
    appall


    In the first test case “hello” all characters domt have same frequency. So it has to be modified in minimum number of operations. The best way is to change ‘l’ to any other character other than ‘h’, ‘e’, ‘o’.One of the possible solutions is “hezlo”.
*/

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MAX_CHAR 26

void getBalancedString()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<vector<int>> at(26);
    for (int i = 0; i < n; i++)
    {
        at[(int)(s[i] - 'a')].push_back(i);
    }
    vector<int> order(26);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int i, int j)
         { return at[i].size() > at[j].size(); });
    string res = "";
    int best = -1;
    for (int cnt = 1; cnt <= 26; cnt++)
    {
        if (n % cnt == 0)
        {
            int cur = 0;
            for (int i = 0; i < cnt; i++)
            {
                cur += min(n / cnt, (int)at[order[i]].size());
            }
            if (cur > best)
            {
                best = cur;
                res = string(n, ' ');
                vector<char> extra;
                for (int it = 0; it < cnt; it++)
                {
                    int i = order[it];
                    for (int j = 0; j < n / cnt; j++)
                    {
                        if (j < (int)at[i].size())
                        {
                            res[at[i][j]] = (char)('a' + i);
                        }
                        else
                        {
                            extra.push_back((char)('a' + i));
                        }
                    }
                }
                for (char &c : res)
                {
                    if (c == ' ')
                    {
                        c = extra.back();
                        extra.pop_back();
                    }
                }
            }
        }
    }
    cout << n - best << '\n';
    cout << res << '\n';
}

int main()
{
    int testCases;
    cin >> testCases;
    while (testCases--)
    {
        getBalancedString();
    }
    return 0;
}
