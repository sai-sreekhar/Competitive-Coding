#include <iostream>
#include <string>
#include <new>
#include <cstdbool>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[n];
    }

    int cutoff = arr[k-1];
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if ((arr[i] >= cutoff) && (arr[i] > 0))
        {
            ans ++;
        }
        
    }
    // printf("%d",ans);
    cout << ans << endl;
    return 0;
}