#include <iostream>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int a, b;
        cin >> a >> b;
        int ans = a;

        if (a < b)
        {
            cout << b - a << "\n";
            continue;
        }
        else if (a == b || a % b == 0)
        {
            cout << 0 << "\n";
            continue;
        }
        int tmp = b;
        int cnt = 2;

        while (tmp <= a)
        {
            tmp *= cnt;
            
            cnt++;
        }
        cout << ans << "\n";
    }
}