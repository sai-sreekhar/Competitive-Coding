#include <bits/stdc++.h>
#define frst first
#define scnd second
#define pb push_back
using namespace std;

long long funFactorArr[100009], pointsToArr[100009], b3[100009], noOfModulesPointed[100009];
vector<int> pointedByArr[100009];
queue<int> leafModuleIdxArr;

void solve()
{
    long long noOfModules, pointsToIdx, minValue, a4, a5 = 0;
    cin >> noOfModules;

    for (int i = 0; i <= noOfModules; i++)
    {
        funFactorArr[i] = pointsToArr[i] = b3[i] = noOfModulesPointed[i] = 0;//initializing all arrays to 0
        pointedByArr[i].clear();
    }
    
    for (int i = 1; i <= noOfModules; i++)
        cin >> funFactorArr[i];

    for (int i = 1; i <= noOfModules; i++)
    {
        cin >> pointsToIdx;
        pointsToArr[i] = pointsToIdx;
        pointedByArr[pointsToIdx].pb(i);
        noOfModulesPointed[pointsToIdx]++;
    }
    for (int i = 0; i <= noOfModules; i++)
        if (noOfModulesPointed[i] == 0)
            leafModuleIdxArr.push(i);

    while (!leafModuleIdxArr.empty())
    {
        pointsToIdx = leafModuleIdxArr.front();
        leafModuleIdxArr.pop();
        minValue = 1 << 30;
        printf("%d\n", minValue);
        for (int i = 0; i < pointedByArr[pointsToIdx].size(); i++)
        {
            if (b3[pointedByArr[pointsToIdx][i]] < minValue)
            {
                minValue = b3[pointedByArr[pointsToIdx][i]];
                a4 = i;
            }
        }
        if (minValue == 1 << 30)
            minValue = 0;
        for (int i = 0; i < pointedByArr[pointsToIdx].size(); i++)
            if (i != a4)
                a5 += b3[pointedByArr[pointsToIdx][i]];
        b3[pointsToIdx] = max(funFactorArr[pointsToIdx], minValue);
        noOfModulesPointed[pointsToArr[pointsToIdx]]--;
        if (noOfModulesPointed[pointsToArr[pointsToIdx]] == 0)
            leafModuleIdxArr.push(pointsToArr[pointsToIdx]);
    }
    cout << a5 + b3[0] << "\n";
    return;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}