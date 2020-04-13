#include <iostream>
#include <cstring>
#include <queue>
#include <limits.h>

using namespace std;

int ans = INT_MAX;
int n, m;
typedef struct info
{
    int y;
    int x;
    int key[7];
} info;

info minsik;

int inside(int y, int x)
{
    return y >= 0 && y < n && x >= 0 && x < m;
}
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
char map[51][51];
bool check[51][51][7];

void BFS()
{
    int ret = 0;
    queue<info> que;
    que.push(minsik);

    while (!que.empty())
    {
        int SIZE = que.size();
        ret++;
        for (int i = 0; i < SIZE; i++)
        {
            info cur = que.front();
            std::cout << cur.y << " " << cur.x << endl;
            if (map[cur.y][cur.x] == '1')
            {
                if (ret < ans)
                    ans = ret;
                return;
            }
            que.pop();
            for (int j = 0; j < 4; j++)
            {
                int dy = cur.y + dir[j][0];
                int dx = cur.x + dir[j][1];
                int flag = 0;
                if (inside(dy, dx) && map[dy][dx] != '#')
                {
                    cout << dy << " " << dx << " " << map[dy][dx] << endl;
                    if (map[dy][dx] == '.' || map[dy][dx] == '0')
                    {
                        cout << "fuxx";
                        for (int k = 0; k < 7; k++)
                        {
                            if (check[dy][dx][k] == false)
                            {
                                flag = 1;
                                break;
                            }
                        }
                        if (flag == 1)
                        {
                            info next;
                            next.y = dy;
                            next.x = dx;
                            for (int k = 0; k < 7; i++)
                            {
                                check[dy][dx][k] = true;
                                next.key[k] = cur.key[k];
                            }
                            que.push(next);
                        }
                        ans = 3;
                        return;
                    }
                    else if (map[dy][dx] >= 'a' && map[dy][dx] <= 'f')
                    {
                        cout << "#";

                        for (int k = 0; k < 7; k++)
                        {
                            if (check[dy][dx][k] == false)
                            {
                                flag = 1;
                                break;
                            }
                        }
                        if (flag == 1)
                        {
                            info next;
                            next.y = dy;
                            next.x = dx;
                            cur.key[map[dy][dx] - 'a' + 1] = 1;
                            for (int k = 0; k < 7; k++)
                            {
                                check[dy][dx][k] = true;
                                next.key[i] = cur.key[i];
                            }
                            que.push(next);
                        }
                    }
                    else if (map[dy][dx] >= 'A' && map[dy][dx] <= 'F')
                    {
                        cout << "#";

                        if (cur.key[map[dy][dx] - 'A' + 'a' + 1] == 1)
                        {
                            for (int k = 0; k < 7; k++)
                            {
                                if (check[dy][dx][k] == false)
                                {
                                    flag = 1;
                                    break;
                                }
                            }
                            if (flag == 1)
                            {
                                info next;
                                next.y = dy;
                                next.x = dx;
                                for (int k = 0; k < 7; k++)
                                {
                                    check[dy][dx][k] = true;
                                    next.key[i] = cur.key[i];
                                }
                                que.push(next);
                            }
                        }
                    }
                    else
                        cout << "$";
                }
            }
        }
    }
    if (ret < ans)
        ans = ret;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == '0')
            {
                for (int k = 0; k < 7; k++)
                    check[i][j][k] = true;
                minsik.y = i;
                minsik.x = j;
                memset(minsik.key, 0, sizeof(minsik.key));
            }
        }
    }

    BFS();

    if (ans == INT_MAX)
        ans = -1;
    cout << ans;
}