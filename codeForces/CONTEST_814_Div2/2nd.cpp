#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{

    int t;
    cin >> t;
    while (t > 0)
    {
        int n, k;
        cin >> n >> k;

        if (n == 2 && k % 4 == 0)
        {
            cout << "NO\n";
        }
        else if (n == 2 && (k % 4 == 3 || k % 4 == 1))
        {
            cout << "YES\n";
            cout << "1 2\n";
        }
        else if (n == 2 && k % 4 == 2)
        {
            cout << "YES\n";
            cout << "2 1\n";
        }
        else if (n == 4 && k % 4 == 0)
        {
            cout << "NO\n";
        }
        else if (n == 4 && (k % 4 == 1 || k % 4 == 3))
        {
            cout << "YES\n";
            cout << "1 2\n";
            cout << "3 4\n";
        }
        else if (n == 4 && k % 4 == 2)
        {
            cout << "YES\n";
            cout << "2 1\n";
            cout << "3 4\n";
        }
        else if (k % 4 == 0)
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
            if (k % 4 == 2)
            {
                int c = 1;
                for (int i = 1; i <= n; i += 2)
                {
                    if (c % 2 == 0)
                    {
                        cout << i << " " << i + 1 << "\n";
                    }
                    else
                    {
                        cout << i + 1 << " " << i << "\n";
                    }
                    c++;
                }
            }
            else
            {
                for (int i = 1; i <= n; i += 2)
                {
                    cout << i << " " << i + 1 << "\n";
                }
            }
        }

        t--;
    }

    return 0;
}