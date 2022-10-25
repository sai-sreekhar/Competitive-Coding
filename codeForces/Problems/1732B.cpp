#include <bits/stdc++.h>

using namespace std;

#define ONLINE_JUDGE

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
        int n;
        cin >> n;
        string str;
        cin >> str;

        int firstNonZeroIdx = -1;
        if (str[0] == '1')
        {
            firstNonZeroIdx = 0;
        }

        int c = 0;
        for (int i = 1; i <= n - 1; i++)
        {
            if (firstNonZeroIdx == -1)
            {
                if (str[i] == '1')
                {
                    firstNonZeroIdx = i;
                }
            }
            else
            {
                if (str[i] != str[i - 1])
                {
                    c++;
                }
            }
        }
        cout << c << "\n";
    }

    return 0;
}
//1100011  -- 2
//110001100 -- 3
//11000110011101 -- 4 00111001100010 000110011101 001100010 0011101 00010 01
//110001101110 001110010001 0001101110 0010001 01110 0001
