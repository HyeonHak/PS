#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int n, m, r, g, ans;
int r_cnt, g_cnt;
int map[51][51];
int covermap[51][51];

vector<int> red, green;

bool check[11];

typedef struct info
{
    int y;
    int x;
} info;
queue<info> RED, GREEN;

vector<info> candidate;
bool inside(int y, int x)
{
    return y >= 0 && y < n && x >= 0 && x < m;
}
int dir[4][2] = {{-1, 0}, {0, 1}, {0, -1}, {0, 1}};

void Input()
{
    info data;
    cin >> n >> m >> r >> g;
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < m; x++)
        {
            cin >> map[y][x];
            if (map[y][x] == 2)
            {
                data.y = y;
                data.x = x;
                candidate.push_back(data);
            }
        }
    }
    r_cnt = r;
    g_cnt = g;
}

void drop()
{
    info data;
    for (int i = 0; i < red.size(); i++)
    {
        map[candidate[red[i]].y][candidate[red[i]].x] = 3;
        data.y = candidate[red[i]].y;
        data.x = candidate[red[i]].x;
        RED.push(data);
    }
    for (int i = 0; i < green.size(); i++)
    {
        map[candidate[green[i]].y][candidate[green[i]].x] = 4;
        data.y = candidate[green[i]].y;
        data.x = candidate[green[i]].x;
        GREEN.push(data);
    }
}

void print_map()
{
    //cout << endl;
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < m; x++)
        {
            covermap[y][x] = map[y][x];
            //  cout << map[y][x] << " ";
        }
        // cout << endl;
    }
    //cout << endl;
}

void recover()
{
    for (int i = 0; i < red.size(); i++)
        map[candidate[red[i]].y][candidate[red[i]].x] = 2;
    for (int i = 0; i < green.size(); i++)
        map[candidate[green[i]].y][candidate[green[i]].x] = 2;
}

void BFS()
{
    int ret = 0;

    while (!RED.empty() || !GREEN.empty())
    {
        int save_map[51][51];
        memset(save_map, 0, sizeof(save_map));

        int red_size = RED.size();
        for (int i = 0; i < red_size; i++)
        {
            info cur = RED.front();

            RED.pop();
            for (int j = 0; j < 4; j++)
            {
                int dy = cur.y + dir[j][0];
                int dx = cur.x + dir[j][1];
                if (inside(dy, dx) && (covermap[dy][dx] == 1 || covermap[dy][dx] == 2))
                    save_map[dy][dx] = 1;
            }
        }
        int green_size = GREEN.size();
        for (int i = 0; i < green_size; i++)
        {
            info cur = GREEN.front();
            GREEN.pop();
            for (int j = 0; j < 4; j++)
            {
                int dy = cur.y + dir[j][0];
                int dx = cur.x + dir[j][1];
                if (inside(dy, dx) && (covermap[dy][dx] == 1 || covermap[dy][dx] == 2))
                {
                    if (save_map[dy][dx] == 1)
                    {
                        covermap[dy][dx] = -1;
                        save_map[dy][dx] = 0;
                        ret++;
                    }
                    else
                        save_map[dy][dx] = 2;
                }
            }
        }
        for (int y_ = 0; y_ < n; y_++)
        {
            for (int x_ = 0; x_ < m; x_++)
            {
                if (save_map[y_][x_] == 1)
                {
                    info data;
                    data.y = y_;
                    data.x = x_;
                    covermap[y_][x_] = 3;
                    RED.push(data);
                }
                else if (save_map[y_][x_] == 2)
                {
                    info data;
                    data.y = y_;
                    data.x = x_;
                    covermap[y_][x_] = 4;
                    GREEN.push(data);
                }
            }
        }
    }
    if (ret > ans)
        ans = ret;
}

void DFS(int cur, int depth, int start)
{
    if (cur == depth && red.size() + green.size() == depth)
    {
        drop();
        print_map();
        BFS();
        recover();
        return;
    }

    for (int i = start; i < candidate.size(); i++)
    {
        if (check[i] == false)
        {
            check[i] = true;
            if (r_cnt > 0)
            {
                r_cnt--;
                red.push_back(i);
                DFS(cur + 1, depth, i);
                red.pop_back();
                r_cnt++;
            }
            if (g_cnt > 0)
            {
                g_cnt--;
                green.push_back(i);
                DFS(cur + 1, depth, i);
                green.pop_back();
                g_cnt++;
            }
            check[i] = false;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    Input();
    DFS(0, r + g, 0);
    cout << ans;
}