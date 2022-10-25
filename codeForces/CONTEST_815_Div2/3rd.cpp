#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif

  int t;
  cin >> t;
  while (t--)
  {
    int n, m;
    cin >> n >> m;
    int arr[n + 2][m + 2];

    for (int i = 0; i < m + 2; i++)
    {
      arr[0][i] = -1;
      arr[n + 1][i] = -1;
    }

    for (int i = 0; i < n + 2; i++)
    {
      arr[i][0] = -1;
      arr[i][m + 1] = -1;
    }

    int onesCount = 0;
    int zeroesCount = 0;
    for (int i = 1; i <= n; i++)
    {
      string binStr;
      cin >> binStr;
      for (int j = 1; j <= m; j++)
      {
        arr[i][j] = binStr[j - 1] - '0';
        if (arr[i][j] == 1)
        {
          onesCount++;
        }
        else
        {
          zeroesCount ++;
        }
        
      }
    }

    // for (int i = 0; i <= n + 1; i++)
    // {
    //   for (int j = 0; j <= m + 1; j++)
    //   {
    //     cout << arr[i][j];
    //   }
    //   cout << "\n";
    // }

    bool found = false;
    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= m; j++)
      {
        if (arr[i][j] == 0)
        {
          if (arr[i][j + 1] == 0 || arr[i + 1][j] == 0 || arr[i + 1, j + 1] == 0 || arr[i, j - 1] == 0 || arr[i + 1][j - 1] == 0 || arr[i - 1][j] == 0 || arr[i - 1][j + 1] == 0 || arr[i - 1][j - 1] == 0)
          {
            found = true;
            break;
          }
        }
      }
    }

    if (onesCount == 0)
    {
      cout << 0 << "\n";
    }
    else if (zeroesCount == 0)
    {
      cout << onesCount -2 << "\n";
    }
    else if (found)
    {
      cout << onesCount << "\n";
    }
    else
    {
      cout << onesCount - 1 << "\n";
    }
  }
  return 0;
}
