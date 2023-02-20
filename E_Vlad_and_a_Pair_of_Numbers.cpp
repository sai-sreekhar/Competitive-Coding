
#include <bits/stdc++.h> 
using namespace std; 
#define int long long 
#define char 1 
#define loop(i, N) for (int i = 0; i < N; i++) 
 
// 2 * (a ^ b) = a + b 
// 2 * (a ^ b) = a ^ b + 2 * (a & b) 
// a ^ b = 2 * (a & b) 
// a ^ b = (a & b) << 1 
// x = a ^ b = (a & b) << 1 
 
// 1111 
// 0101 
// 10010 
 
void solve() 
{ 
    int x; 
    cin >> x; 
 
    bool flag = false; 
    int i = 0; 
    int a = 0, b = 0; 
    while (i < 32) 
    { 
        if (!(x & (1 << i))) 
        { 
            if (x & (1 << (i + 1))) 
            { 
                a += 1 << i; 
                a += 1 << (i + 1); 
                b += 1 << i; 
                i++; 
            } 
        } 
        else 
        { 
            cout << -1 << endl; 
            return; 
        } 
        i++; 
    } 
    cout << a << ' ' << b << endl; 
} 
 
int32_t main() 
{ 
    ios_base::sync_with_stdio(false); 
    cin.tie(0); 
    int T = 1; 
    cin >> T; 
 
    while (T--) 
        solve(); 
}