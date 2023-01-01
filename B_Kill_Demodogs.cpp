#include <bits/stdc++.h>

using namespace std;

#define ll long long

void getMaxDemoDogs()
{
    ll n;
    cin >> n;

    // cout << "n: " << n << "\n";
    int year = 337;
    int toDivide = 1000000000 + 7;

    ll maxDemoDogs = n * (n + 1) % toDivide;
    // cout << "maxDemoDogs: " << maxDemoDogs << "\n";
    maxDemoDogs *= (4 * n % toDivide - 1 + toDivide) % toDivide;
    // cout << "maxDemoDogs: " << maxDemoDogs << "\n";

    maxDemoDogs %= toDivide;
    // cout << "maxDemoDogs: " << maxDemoDogs << "\n";

    maxDemoDogs *= year;
    // cout << "maxDemoDogs: " << maxDemoDogs << "\n";

    maxDemoDogs %= toDivide;

    cout << maxDemoDogs << "\n";
}

int main()
{
    ll testCases;
    cin >> testCases;
    while (testCases--)
    {
        getMaxDemoDogs();
    }
    return 0;
}