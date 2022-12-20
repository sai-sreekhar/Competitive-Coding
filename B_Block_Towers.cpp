#include <bits/stdc++.h>

using namespace std;

#define lli long long int

void solve()
{
    int n;
    cin >> n;
    int arrayofTowers[n];
    stack<int> stack;
    for (int i = 0; i < n; i++)
    {
        cin >> arrayofTowers[i];
    }

    int firstTower = arrayofTowers[0];
    sort(arrayofTowers, arrayofTowers + n);
    for (int i = n - 1; i >= 0; i--)
    {
        if (arrayofTowers[i] > firstTower)
            stack.push(arrayofTowers[i]);
    }

    while (!stack.empty())
    {
        int top = stack.top();
        if (top > firstTower)
        {
            int change;
            if ((top - firstTower) % 2 != 0)
            {
                change = (top - firstTower) / 2 + 1;
                firstTower += change;
                top -= change;
                stack.pop();
            }
            else
            {
                change = (top - firstTower) / 2;
                firstTower += change;
                top -= change;
                stack.pop();
            }
        }
        else
        {
            stack.pop();
        }
    }

    cout << firstTower << "\n";
}

int main()
{
    int testCases;
    cin >> testCases;
    while (testCases--)
    {
        solve();
    }
    return 0;
}