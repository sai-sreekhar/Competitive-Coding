#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string arr[2][n];
    int blackCount = 0;
    int visited[2][n];
    int firstWhiteCol = -1;
    int firstWhiteRow = -1;
    for (int i = 0; i < 2; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < s.size(); j++)
        {
            arr[i][j] = s[j];
            visited[i][j] = 0;
            if (arr[i][j] == "B")
            {
                blackCount++;
            }
            if (arr[i][j] == "W")
            {
                if (firstWhiteCol == -1)
                {
                    firstWhiteCol = j;
                    firstWhiteRow = i;
                }
                else if (firstWhiteCol > j)
                {
                    firstWhiteCol = j;
                    firstWhiteRow = i;
                }
            }
        }
    }

    int i;
    int j;
    if (arr[0][0] == "B" && arr[1][0] == "B")
    {
        if (firstWhiteRow == 0)
        {
            if (firstWhiteCol % 2 == 0)
            {
                i = 1;
                j = 0;
            }
            else
            {
                i = 0;
                j = 0;
            }
        }
        else if (firstWhiteRow == 1)
        {
            if (firstWhiteCol % 2 != 0)
            {
                i = 1;
                j = 0;
            }
            else
            {
                i = 0;
                j = 0;
            }
        }
        else
        {
            i = 0;
            j = 0;
        }
    }
    else if (arr[0][0] == "B")
    {
        i = 0;
        j = 0;
    }
    else if (arr[1][0] == "B")
    {
        i = 1;
        j = 0;
    }
    else
    {
        cout << "NO" << endl;
        return;
    }

    int c = 1;
    visited[i][j] = 1;
    while (i >= 0 && i <= 1 && j >= 0 && j < n)
    {

        if (i == 0 && arr[1][j] == "B" && visited[1][j] == 0)
        {
            i = 1;
            c++;
            visited[i][j] = 1;
        }
        else if (i == 1 && arr[0][j] == "B" && visited[0][j] == 0)
        {
            i = 0;
            c++;
            visited[i][j] = 1;
        }
        else if (j + 1 <= n - 1 && arr[i][j + 1] == "B" && visited[i][j + 1] == 0)
        {
            j++;
            c++;
            visited[i][j] = 1;
        }
        else
        {
            break;
        }
    }

    if (c != blackCount)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
    }
}

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
