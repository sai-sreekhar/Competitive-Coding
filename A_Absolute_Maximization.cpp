#include <bits/stdc++.h>

using namespace std;

void display()
{
    int n;
    cin >> n;
    int inputArr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> inputArr[i];
    }

    int numAtIdx0 = inputArr[0];
    int numAtIdx0Dup = inputArr[0];

    for (int i = 1; i < n; i++)
    {
        numAtIdx0Dup = numAtIdx0Dup & inputArr[i];
        numAtIdx0 = numAtIdx0 | inputArr[i];
    }

    cout << numAtIdx0 - numAtIdx0Dup << "\n";
}

int main()
{
    int testCases;
    cin >> testCases;
    while (testCases--)
    {
        display();
    }
    return 0;
}