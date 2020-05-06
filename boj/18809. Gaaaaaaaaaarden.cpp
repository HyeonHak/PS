#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef struct Info
{
    int y;
    int x;
    int color;
} info;

int n, m, g, r, ans;
int g_cnt;
int r_cnt;
int map[51][51];
int new_map[51][51];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int map_state[51][51];
vector<info> candidate;
info input;

int inside(int y, int x)
{
    return y >= 0 && y < n && x >= 0 && x < m;
}

void Input()
{
    cin >> n >> m >> g >> r;
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < m; x++)
        {
            cin >> map[y][x];
            if (map[y][x] == 2)
            {
                input.y = y;
                input.x = x;
                candidate.push_back(input);
            }
        }
    }
    g_cnt = g;
    r_cnt = r;
}

void copy()
{
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < m; x++)
        {
            new_map[y][x] = map[y][x];
            map_state[y][x] = 0;
        }
    }
}

void drop()
{
    queue<info> que;
    for (int i = 0; i < candidate.size(); i++)
    {
        info cur = candidate[i];
        new_map[cur.y][cur.x] = cur.color;
        map_state[cur.y][cur.x] = cur.color;
        que.push(cur);
    }

    while (!que.empty())
    {
        int SIZE = que.size();
        for (int i = 0; i < SIZE; i++)
        {
            info cur = que.front();
            que.pop();
            cout << cur.y << " " << cur.x << endl;
            for (int j = 0; j < 4; j++)
            {
                int dy = cur.y + dir[j][0];
                int dx = cur.x + dir[j][1];
                if (inside(dy, dx) && (new_map[dy][dx] == 1 || new_map[dy][dx] == 2) && map_state[dy][dx] != cur.color)
                {
                    if (map_state[dy][dx] == 5)
                        continue;
                    else if (map_state[dy][dx] != 0)
                    {
                        map_state[dy][dx] = 5;
                        new_map[dy][dx] = 5;
                        ans++;
                        continue;
                    }
                    else if (map_state[dy][dx] == 0)
                        map_state[dy][dx] = cur.color;
                }
            }
            cout << endl;
            for (int y = 0; y < n; y++)
            {
                for (int x = 0; x < m; x++)
                {
                    cout << map_state[y][x] << " ";
                }
                cout << endl;
            }
        }

        for (int y = 0; y < n; y++)
        {
            for (int x = 0; x < m; x++)
            {
                if (map_state[y][x] != 0 && map_state[y][x] != 5)
                {
                    info next;
                    next.y = y;
                    next.x = x;
                    que.push(next);
                }
            }
        }
    }
}

void DFS(int cur)
{
    if (cur == g + r)
    {
        copy();
        drop();
        return;
    }
    if (g_cnt > 0)
    {
        g_cnt -= 1;
        candidate[cur].color = 3;
        DFS(cur + 1);
        g_cnt += 1;
    }
    if (r_cnt > 0)
    {
        r_cnt -= 1;
        candidate[cur].color = 4;
        DFS(cur + 1);
        r_cnt += 1;
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Input();
    DFS(0);
    cout << ans;
}