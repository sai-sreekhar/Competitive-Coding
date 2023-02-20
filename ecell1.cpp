#include <iostream>
using namespace std;

int main()
{
    string s, t;
    cin >> s >> t;
    cout << max(abs(s[0] - t[0]), abs(s[1] - t[1])) << "\n";
    return 0;
}