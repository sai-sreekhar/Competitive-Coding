#include <iostream>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int x = s[0] - 'a' + 1;
    int y = s[1] - '1' + 1;
    cout << 28 - abs(x - y) - abs(x + y - 9) << "\n";
}