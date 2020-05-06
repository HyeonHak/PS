#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

int n, m, ans;
int map[1001][1001];
int visit[1001][1001];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
bool CHECK[1000001];

vector<int> S;
typedef struct info
{
    int y;
    int x;
} info;
int inside(int y, int x)
{
    return y >= 0 && y < n && x >= 0 && x < m;
}
int cnt = 1;

void BFS(int y, int x)
{
    info data;
    data.y = y;
    data.x = x;
    queue<info> que;
    que.push(data);
    visit[y][x] = cnt;
    int s = 1;

    while (!que.empty())
    {
        int SIZE = que.size();
        for (int i = 0; i < SIZE; i++)
        {
            info cur = que.front();
            que.pop();
            for (int j = 0; j < 4; j++)
            {
                int dy = cur.y + dir[j][0];
                int dx = cur.x + dir[j][1];
                if (inside(dy, dx) && visit[dy][dx] == 0 && map[dy][dx] == 1)
                {
                    visit[dy][dx] = cnt;
                    info next;
                    next.y = dy;
                    next.x = dx;
                    que.push(next);
                    s++;
                }
            }
        }
    }
    S.push_back(s);
}

void is_possible(int y, int x)
{
    vector<int> vec;
    int ret = 0;

    for (int i = 0; i < 4; i++)
    {
        int dy = y + dir[i][0];
        int dx = x + dir[i][1];
        if (inside(dy, dx) && visit[dy][dx] != 0)
            vec.push_back(visit[dy][dx]);
    }
    if (!vec.empty())
        memset(CHECK, false, cnt);
    else
        return;

    for (int i = 0; i < vec.size(); i++)
    {
        if (CHECK[vec[i]] == false)
        {
            ret += S[vec[i] - 1];
            CHECK[vec[i]] = true;
        }
    }
    if (ret > ans)
        ans = ret;
}

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

    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < m; x++)
        {
            if (map[y][x] == 1 && visit[y][x] == 0)
            {
                BFS(y, x);
                cnt++;
            }
        }
    }
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < m; x++)
        {
            if (map[y][x] == 0)
            {
                is_possible(y, x);
            }
        }
    }

    cout << ans + 1;
}