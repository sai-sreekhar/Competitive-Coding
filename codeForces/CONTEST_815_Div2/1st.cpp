#include <bits/stdc++.h>
#include <cmath>

using namespace std;

int main()
{

  int t;
  cin >> t;
  while (t--)
  {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a == 0 && c == 0)
    {
      cout << 0 << "\n";
    }
    else if (a == 0 || c == 0)
    {
      cout << 1 << "\n";
    }
    else
    {
      if ((c * b) % (a * d) != 0)
      {
        if ((a * d) % (b * c) == 0)
        {

          cout << 1 << "\n";
        }
        else
        {
          cout << 2 << "\n";
        }
      }
      else
      {
        long long res = (c * b) / (a * d);
        if (res == 1)
        {
          cout << 0 << "\n";
        }
        else
        {
          cout << 1 << "\n";
        }
      }
    }
  }
  return 0;
}
