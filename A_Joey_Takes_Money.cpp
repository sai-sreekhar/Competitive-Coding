#include <bits/stdc++.h>

using namespace std;

#define ll long long int

void getAnswer()
{
    const int year = 2022;
    int n;
    cin >> n;
    int arr[n];
    ll product = 1;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        product = product * arr[i];
    }

    cout << (product + (n - 1)) * year << "\n";
}

int main()
{
    int testCases;
    cin >> testCases;
    while (testCases--)
    {
        getAnswer();
    }
    return 0;
}