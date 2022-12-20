#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void calcCountOfWinningPlayers()
{
    int n;
    cin >> n;
    string environmentStr;
    cin >> environmentStr;

    char envAtZeroIdx = environmentStr[0];
    int outputRes = 1;
    int tempRes = 0;
    for (int k = 0; k < environmentStr.length(); k++)
    {
        tempRes++;
        if (envAtZeroIdx == environmentStr[k])
        {
            cout << outputRes << " ";
        }
        else
        {
            outputRes = tempRes;
            envAtZeroIdx = environmentStr[k];
            cout << outputRes << " ";
        }
    }
    cout << "\n";   
    return;
}

int main()
{
    int testCases;
    cin >> testCases;
    while (testCases--)
    {
        calcCountOfWinningPlayers();
    }
    return 0;
}