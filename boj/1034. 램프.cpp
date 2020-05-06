#include <iostream>
using namespace std;

char map[51][51];
int n, m, k;
int ans;
int arr[1001];
int value[1001];

void on(int row)
{
    for (int y = 1; y <= n; y++)
    {
        if (map[y][row] == '0')
            map[y][row] = '1';
        else
            map[y][row] = '0';
    }
}

int calc()
{
    int ret = 0;
    for (int y = 1; y <= n; y++)
    {
        int tmp = 0;
        for (int x = 1; x <= m; x++)
        {
            if (map[y][x] == '1')
                tmp++;
        }
        if (tmp > ret)
            ret = tmp;
    }
    return (ret);
}

void DFS(int cur)
{
    if (cur == k)
    {
        for (int i = 0; i < k; i++)
        {
            int cnt = 0;
            for (int j = i + 1; j < k; j++)
            {
                if (value[i] == value[j])
                    cnt++;
                else
                {
                    i = j - 1;
                    break;
                }
            }
            if (cnt % 2 == 1 || cnt == 0)
                on(arr[i]);
        }
        int tmp = calc();
        if (ans < tmp)
            ans = tmp;
        return;
    }

    for (int i = 1; i <= m; i++)
    {
        arr[cur] = i;
        DFS(cur + 1);
    }
}
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int y = 1; y <= n; y++)
    {
        for (int x = 1; x <= m; x++)
        {
            cin >> map[y][x];
        }
    }
    cin >> k;
    DFS(0);
    cout << ans;
}