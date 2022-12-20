#include <bits/stdc++.h>

using namespace std;

void getResult()
{
    int k, n;
    cin >> k >> n;
    int arr[n + 1];
    for (int curIdx = 0; curIdx <= n; curIdx++)
    {
        arr[curIdx] = curIdx;
    }

    int filledNumbers = 0;
    int curIdx = 1;
    bool isPossible = false;
    while (filledNumbers < k)
    {
        // Fill the current position with the number of filled numbers
        filledNumbers++;
        if (isPossible)
        {
            cout << arr[curIdx] << " ";
            curIdx++;
        }

        // If it is not possible to fill the next position, then fill the next position
        if (!isPossible)
        {
            cout << arr[curIdx] << " ";
            // Move the index to the next position, based on the number of filled numbers
            curIdx += filledNumbers;
            // If the next position is not possible, then move to the next position
            if (curIdx > n || arr[n] - arr[curIdx] + 1 < k - filledNumbers)
            {
                isPossible = true;
                curIdx -= filledNumbers;
                curIdx++;
            }
        }
    }

    cout << "\n";
}

int main()
{
    int testCases;
    cin >> testCases;
    while (testCases--)
    {
        getResult();
    }
    return 0;
}