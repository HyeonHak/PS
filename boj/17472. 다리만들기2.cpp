#include <iostream>
#include <limits.h>
using namespace std;
int n, m;
int map[12][12];
int ans = INT_MAX;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < m; x++)
        {
            cin >> map[y][x];
        }
    }


    if (ans == INT_MAX)
        ans = -1;
    cout << ans;
}