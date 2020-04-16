#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(int a, int b)
{
    return a > b;
}
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin >> tc;
    for (int i = 0; i < tc; i++)
    {
        int n;
        int input;
        int ans = 0;
        cin >> n;
        int arr[n + 1];
        memset(arr, 0, sizeof(arr));
        for (int j = 0; j < n; j++)
        {
            cin >> input;
            arr[input]++;
        }
        sort(arr, arr + n + 1, compare);
        for (int i = 1; i < n; i++)
        {
            if (arr[i] == 0)
                break;
            ans++;
        }
        if (ans == arr[0])
            ans = arr[0];
        else if (ans > arr[0])
            ans = arr[0];
        else if (ans < arr[0])
        {
            if (ans + 1 != arr[0])
                ans = ans + 1;
            else
                ans = ans;
        }
        cout << ans << "\n";
    }
}