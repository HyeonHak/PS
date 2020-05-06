#include <iostream>
#include <vector>
using namespace std;

int n, k;
int map[13][13];
vector<int> map_state[13][13];

int dir[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int change_dir[4] = {1, 0, 3, 2};
bool inside(int y, int x)
{
    return y >= 1 && y <= n && x >= 1 && x <= n;
}

typedef struct info
{
    int y;
    int x;
    int d;
} info;

info horse[11];

void move(int num)
{
    info cur = horse[num];
    int dy = cur.y + dir[horse[num].d][0];
    int dx = cur.x + dir[horse[num].d][1];

    if (!inside(dy, dx) || map[dy][dx] == 2)
    {
        horse[num].d = change_dir[horse[num].d];
        move(num);
    }
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n >> k;

    for (int y = 1; y <= n; y++)
    {
        for (int x = 1; x <= n; x++)
        {
            cin >> map[y][x];
        }
    }

    for (int i = 1; i <= k; i++)
    {
        int y, x, d;
        cin >> y >> x >> d;
        horse[i] = {y, x, d};
        map_state[y][x].push_back(i);
    }

    for (int i = 1; i <= k; i++)
    {
        info cur = horse[i];
        if (map_state[cur.y][cur.x].front() != i)
            continue;
        move(i);
    }

    return (0);
}