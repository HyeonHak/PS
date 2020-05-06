#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dir[5][2] = {{0, 0}, {-1, 0}, {1, 0}, {0, 1}, {0, -1}};
int change_dir[5] = {0, 2, 1, 4, 3};
int R, C, m;
int map[101][101];
vector<int> map_state[101][101];

int ans;

int inside(int y, int x)
{
    return y >= 1 && y <= R && x >= 1 && x <= C;
}

typedef struct info
{
    int r;
    int c;
    int s;
    int d;
    int z;
} info;

info shark[10002];
bool compare(int a, int b)
{
    return shark[a].z > shark[b].z;
}

void hunt(int dx)
{
    for (int y = 1; y <= R; y++)
    {
        if (map[y][dx] != 0 && shark[map[y][dx]].z != 0)
        {
            ans += shark[map[y][dx]].z;
            shark[map[y][dx]] = {0, 0, 0, 0, 0};
            map[y][dx] = 0;
            return;
        }
    }
}

void shark_move()
{
    for (int i = 1; i <= m; i++)
        map_state[shark[i].r][shark[i].c].clear();
        
    for (int i = 1; i <= m; i++)
    {

        map[shark[i].r][shark[i].c] = 0;
        if (shark[i].z == 0)
            continue;
        int cnt = 0;
        if (shark[i].d == 1 || shark[i].d == 2)
            cnt = shark[i].s % ((R - 1) * 2);
        else
            cnt = shark[i].s % ((C - 1) * 2);

        int dy = shark[i].r;
        int dx = shark[i].c;
        for (int j = 0; j < cnt; j++)
        {
            dy += dir[shark[i].d][0];
            dx += dir[shark[i].d][1];
            if (!inside(dy, dx))
            {
                shark[i].d = change_dir[shark[i].d];
                dy += dir[shark[i].d][0];
                dx += dir[shark[i].d][1];
                j--;
            }
        }
        map_state[dy][dx].push_back(i);
        shark[i].r = dy;
        shark[i].c = dx;
    }
}

void eatting()
{
    for (int i = 1; i <= m; i++)
    {
        if (shark[i].z == 0)
            continue;
        sort(map_state[shark[i].r][shark[i].c].begin(), map_state[shark[i].r][shark[i].c].end(), compare);
        for (int j = 1; j < map_state[shark[i].r][shark[i].c].size(); j++)
            shark[map_state[shark[i].r][shark[i].c][j]].z = 0;
        map[shark[i].r][shark[i].c] = map_state[shark[i].r][shark[i].c][0];
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> R >> C >> m;
    for (int i = 1; i <= m; i++)
    {
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;
        shark[i] = {r, c, s, d, z};
        map[r][c] = i;
    }

    for (int i = 1; i <= C + 1; i++)
    {
        hunt(i);
        shark_move();
        eatting();
    }
    cout << ans;
}