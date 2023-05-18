#include <bits/stdc++.h>

using namespace std;

void bactrackFunc(int begin, int target, vector<int> &factors, vector<vector<int>> &allCombinationsVec, int n)
{
    if (target == 1)
    {
        if (factors.size() > 1 || factors[0] != n)
        {
            allCombinationsVec.push_back(factors);
        }
        return;
    }

    for (int i = begin; i <= target; i++)
    {
        if (target % i == 0)
        {
            factors.push_back(i);
            bactrackFunc(i, target / i, factors, allCombinationsVec, n);
            factors.pop_back();
        }
    }
}

vector<vector<int>> factorCombinations(int n)
{
    vector<vector<int>> allCombinationsVec;
    vector<int> factors;
    bactrackFunc(2, n, factors, allCombinationsVec, n);
    return allCombinationsVec;
}

int getDigitsSum(int n)
{
    int sum = 0;
    while (n > 0 || sum > 9)
    {
        if (n == 0)
        {
            n = sum;
            sum = 0;
        }
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int getSmallestNum(int n, int k)
{
    vector<vector<int>> allCombinationsVec = factorCombinations(k);
    int smallestNum = -1;
    for (int i = 0; i < allCombinationsVec.size(); i++)
    {
        vector<int> digits = allCombinationsVec[i];
        int newNum = 0;
        for (auto d : digits)
        {
            newNum = newNum * 10 + d;
        }
        int sum = getDigitsSum(newNum);
        if (sum == n && (smallestNum == -1 || newNum < smallestNum))
        {
            smallestNum = newNum;
        }
    }
    return smallestNum;
}

int main()
{
    int n, k;
    cin >> n >> k;
    cout << getSmallestNum(n, k) << "\n";
    return 0;
}
