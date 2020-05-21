#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, k;
int dir[5][2] = {{0, 0}, {0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int cdir[5] = {0, 2, 1, 4, 3};
int map[14][14];
vector<int> map_state[14][14];

typedef struct info
{
    int y;
    int x;
    int d;
} info;
info input;

bool inside(int y, int x)
{
    return y >= 1 && y <= n && x >= 1 && x <= n;
}

vector<info> horse;

void Input()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cin >> map[i][j];
    }
    horse.push_back(input);
    for (int i = 1; i <= k; i++)
    {
        cin >> input.y >> input.x >> input.d;
        horse.push_back(input);
        map_state[input.y][input.x].push_back(i);
    }
}

int Move(int number)
{
    info cur = horse[number];
    int dy = cur.y + dir[cur.d][0];
    int dx = cur.x + dir[cur.d][1];

    if (!inside(dy, dx) || map[dy][dx] == 2)
    {
        horse[number].d = cdir[cur.d];
        dy = cur.y + dir[horse[number].d][0];
        dx = cur.x + dir[horse[number].d][1];
        if (!inside(dy, dx) || map[dy][dx] == 2)
            return map_state[cur.y][cur.x].size();
        else
            return Move(number);
    }
    else if (map[dy][dx] == 0)
    {
        for (int i = 0; i < map_state[cur.y][cur.x].size(); i++)
        {
            horse[map_state[cur.y][cur.x][i]].y = dy;
            horse[map_state[cur.y][cur.x][i]].x = dx;
            map_state[dy][dx].push_back(map_state[cur.y][cur.x][i]);
        }
        map_state[cur.y][cur.x].clear();
        return map_state[dy][dx].size();
    }
    else if (map[dy][dx] == 1)
    {
        reverse(map_state[cur.y][cur.x].begin(), map_state[cur.y][cur.x].end());
        for (int i = 0; i < map_state[cur.y][cur.x].size(); i++)
        {
            horse[map_state[cur.y][cur.x][i]].y = dy;
            horse[map_state[cur.y][cur.x][i]].x = dx;
            map_state[dy][dx].push_back(map_state[cur.y][cur.x][i]);
        }
        map_state[cur.y][cur.x].clear();
        return map_state[dy][dx].size();
    }
    return 0;
}

int Solve()
{
    int ret = 1;
    while (1)
    {
        if (ret >= 1000)
            return -1;
        for (int i = 1; i <= k; i++)
        {
            if (map_state[horse[i].y][horse[i].x].front() != i)
                continue;
            if (Move(i) >= 4)
                return ret;
        }
        ret++;
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Input();
    cout << Solve();
}
