#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n][3];

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int presentQsnMajority = 0;
        for (int j = 0; j < 3; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 1)
            {
                presentQsnMajority ++;
            }
        }

        if (presentQsnMajority >= 2)
        {
            ans ++;
        }
        
    }

    cout << ans << endl;
    return 0;
}