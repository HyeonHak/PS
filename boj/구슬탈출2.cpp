#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct Info
{
    int rx, ry;
    int bx, by;
    int count = 0;
};
Info start;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

queue<Info> q;
int n, m, ans = 0;
char map[11][11];
bool visit[11][11][11][11];

int bfs()
{
    q.push(start);
    visit[start.ry][start.rx][start.by][start.bx] = true;

    while (!q.empty())
    {

        Info cur = q.front();
        q.pop();
        //cout << cur.by << " " << cur.bx << " " << cur.ry << " " << cur.rx << endl;
        if (cur.count > 10)
        {
            ans = -1;
            return -1;
        }
        if (map[cur.ry][cur.rx] == 'O' && map[cur.by][cur.bx] != 'O')
        {
            return cur.count;
        }

        for (int i = 0; i < 4; i++)
        {
            int next_bx = cur.bx;
            int next_by = cur.by;
            int next_rx = cur.rx;
            int next_ry = cur.ry;

            while (1)
            {
                if (map[next_by][next_bx] != '#' && map[next_by][next_bx] != 'O')
                {
                    next_bx += dir[i][1];
                    next_by += dir[i][0];
                }
                else
                {
                    if (map[next_by][next_bx] == '#')
                    {
                        next_bx -= dir[i][1];
                        next_by -= dir[i][0];
                    }
                    break;
                }
            }
            while (1)
            {
                if (map[next_ry][next_rx] != '#' && map[next_ry][next_rx] != 'O')
                {
                    next_rx += dir[i][1];
                    next_ry += dir[i][0];
                }
                else
                {
                    if (map[next_ry][next_rx] == '#')
                    {
                        next_rx -= dir[i][1];
                        next_ry -= dir[i][0];
                    }
                    break;
                }
            }

            if (next_rx == next_bx && next_ry == next_by && map[next_ry][next_rx] != 'O')
            {
                //cout << "T";
                int red_dist = abs(next_rx - cur.rx) + abs(next_ry - cur.ry);
                int blue_dist = abs(next_bx - cur.bx) + abs(next_by - cur.by);
                if (red_dist > blue_dist)
                {
                    next_rx -= dir[i][1];
                    next_ry -= dir[i][0];
                }
                else
                {
                    next_by -= dir[i][0];
                    next_bx -= dir[i][1];
                }
            }

            if (!visit[next_ry][next_rx][next_by][next_bx])
            {
                visit[next_ry][next_rx][next_by][next_bx] = true;
                Info next;
                next.by = next_by;
                next.bx = next_bx;
                next.ry = next_ry;
                next.rx = next_rx;
                next.count = cur.count + 1;
                q.push(next);
            }
        }
    }

    return -1;
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for (int y = 1; y <= n; y++)
    {
        for (int x = 1; x <= m; x++)
        {
            cin >> map[y][x];
            if (map[y][x] == 'B')
            {
                start.bx = x;
                start.by = y;
            }
            else if (map[y][x] == 'R')
            {
                start.rx = x;
                start.ry = y;
            }
        }
    }

    cout << bfs();
}