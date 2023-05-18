#include <iostream>
#include <vector>
using namespace std;

bool isSubString(string s1, string s2)
{
    int M = s1.length();
    int N = s2.length();

    for (int i = 0; i <= N - M; i++)
    {
        int j;
        for (j = 0; j < M; j++)
            if (s2[i + j] != s1[j])
                break;

        if (j == M)
            return true;
    }

    return false;
}

int main()
{
    int n;
    cin >> n;
    vector<string> vec;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        vec.push_back(s);
    }

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (isSubString(vec[i], vec[j]) || isSubString(vec[j], vec[i]))
            {
                count++;
            }
        }
    }

    cout << count << endl;
}