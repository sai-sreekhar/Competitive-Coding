/*
    Author: Sai Sreekar
    Test Case Description:
    First line contains an integer T (between 1 and 150) which stands for the number of testcases.
    Each TestCase has 2 lines.
    First Line of each testcase contains an integer n (1 <= n <= 100)
    Second Line of each testcase contains n space separated positive integers (1 <= a[i] <= 1000)
*/

/*
    Logic:
    Sparse Table
    Sample Input:
    3
    5
    1 2 3 4 5
    7
    4 7 8 3 2 1 9
    10
    6 3 1 8 2 6 9 23 12 5
    Sample Output:
    1 1 1
    2 2 2
    3 3
    4 4
    5
    4 4 3
    7 7 2
    8 3 1
    3 2 1
    2 1
    1 1
    9
    6 3 1 1 
    3 1 1 1 
    1 1 1 1 
    8 2 2 
    2 2 2 
    6 6 6 
    9 9 5 
    23 12 
    12 5 
    5 
*/

#include <bits/stdc++.h>
using namespace std;
#define MAX 10000

int sparseTable[10000][10000];

void buildSparseTable(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        sparseTable[i][0] = arr[i];
    }

    for (int j = 1; (1 << j) <= n; j++)
    {
        for (int i = 0; (i + (1 << j) - 1) < n; i++)
        {
            if (sparseTable[i][j - 1] <
                sparseTable[i + (1 << (j - 1))][j - 1])
            {
                sparseTable[i][j] = sparseTable[i][j - 1];
            }
            else
            {
                sparseTable[i][j] =
                    sparseTable[i + (1 << (j - 1))][j - 1];
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        memset(sparseTable, -1, sizeof(sparseTable));
        buildSparseTable(arr, n);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (sparseTable[i][j] != -1)
                {
                    cout << sparseTable[i][j] << " ";
                }
            }
            cout << "\n";
        }
    }
    return 0;
}
