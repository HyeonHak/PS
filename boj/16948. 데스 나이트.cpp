#include <iostream>
#include <queue>
using namespace std;
int map[210][210];
int sy, sx, ey, ex;
bool check[210][210];
int ans, n;
int dir[6][2] = {{-2, -1}, {-2, 1}, {0, -2}, {0, 2}, {2, -1}, {2, 1}};

typedef struct info
{
    int y;
    int x;
} info;
queue<info> que;

int inside(int y, int x)
{
    return y >= 0 && y < n && x >= 0 && x < n;
}

void BFS()
{
    info data;
    data.y = sy;
    data.x = sx;
    que.push(data);
    check[sy][sx] = true;
    while (!que.empty())
    {
        int SIZE = que.size();
        for (int i = 0; i < SIZE; i++)
        {
            info cur = que.front();
            if (cur.y == ey && cur.x == ex)
                return;
            que.pop();
            for (int j = 0; j < 6; j++)
            {
                int dy = cur.y + dir[j][0];
                int dx = cur.x + dir[j][1];
                if (inside(dy, dx) && check[dy][dx] == false)
                {
                    check[dy][dx] = true;
                    info next;
                    next.y = dy;
                    next.x = dx;
                    que.push(next);
                }
            }
        }
        ans++;
    }
    ans = -1;
}
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    cin >> sy >> sx >> ey >> ex;
    BFS();
    cout << ans;
}