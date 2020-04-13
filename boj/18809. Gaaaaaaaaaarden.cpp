#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int n, m, g, r;
int DEPTH;
int map[51][51];
int new_map[51][51];
int check[110];
int ans;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

typedef struct info
{
    int y;
    int x;
} info;
queue<info> red, green;

vector<pair<int, int>> arr;

bool inside(int y, int x)
{
    return y >= 0 && y < n && x >= 0 && x < m;
}
vector<info> vec;
info input;

void print_map()
{
    cout << endl;
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < m; x++)
        {
            cout << new_map[y][x] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void drop()
{
    info tmp;

    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < m; x++)
        {
            new_map[y][x] = map[y][x];
        }
    }
    for (int i = 0; i < arr.size(); i++)
    {
        pair<int, int> cur = arr[i];
        info cover_map = vec[cur.first];
        new_map[cover_map.y][cover_map.x] = cur.second;
        if (cur.second == 3)
        {
            tmp.y = cover_map.y;
            tmp.x = cover_map.x;
            green.push(tmp);
        }
        else if (cur.second == 4)
        {
            tmp.y = cover_map.y;
            tmp.x = cover_map.x;
            red.push(tmp);
        }
    }
}

void BFS()
{
    int ret = 0;
    info tmp;

    while (!red.empty() || !green.empty())
    {
        int tmp_map[51][51];
        memset(tmp_map, 0, sizeof(tmp_map));

        int red_size = red.size();

        for (int i = 0; i < red_size; i++)
        {
            info cur = red.front();
            red.pop();
            for (int j = 0; j < 4; j++)
            {
                int dy = cur.y + dir[j][0];
                int dx = cur.x + dir[j][1];
                if (inside(dy, dx) && (new_map[dy][dx] == 2 || new_map[dy][dx] == 1))
                {
                    new_map[dy][dx] = 4;
                    tmp.y = dy;
                    tmp.x = dx;
                    red.push(tmp);
                    tmp_map[dy][dx] = 1;
                }
            }
        }

        int green_size = green.size();
        for (int i = 0; i < green_size; i++)
        {
            info cur = green.front();
            green.pop();
            for (int j = 0; j < 4; j++)
            {
                int dy = cur.y + dir[j][0];
                int dx = cur.x + dir[j][1];
                if (inside(dy, dx) && new_map[dy][dx] != 0 && new_map[dy][dx] != 3)
                {
                    if (tmp_map[dy][dx] == 1)
                    {
                        ret++;
                        continue;
                    }
                    new_map[dy][dx] = 3;
                    tmp.y = dy;
                    tmp.x = dx;
                    green.push(tmp);
                }
            }
        }
    }

    if (ret > ans)
        ans = ret;
}

void DFS(int depth, int start)
{
    if (depth == DEPTH)
    {
        drop();
        BFS();
        return;
    }

    for (int i = start; i < vec.size(); i++)
    {
        if (check[i] == false)
        {
            check[i] = true;
            if (g != 0)
            {
                g--;
                arr.push_back(pair<int, int>(i, 3));
                DFS(depth + 1, i);
                arr.pop_back();
                g++;
            }
            if (r != 0)
            {
                r--;
                arr.push_back(pair<int, int>(i, 4));
                DFS(depth + 1, i);
                arr.pop_back();
                r++;
            }
            check[i] = false;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> g >> r;
    DEPTH = g + r;
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < m; x++)
        {
            cin >> map[y][x];
            if (map[y][x] == 2)
            {
                input.y = y;
                input.x = x;
                vec.push_back(input);
            }
        }
    }

    DFS(0, 0);
    cout << ans;
}