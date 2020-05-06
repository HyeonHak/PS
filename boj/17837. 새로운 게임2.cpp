#include <iostream>
#include <vector>
using namespace std;
int n, k;
int map[13][13];
int h_map[13][13];
bool inside(int y, int x)
{
    return y >= 1 && y <= n && x >= 1 && x <= n;
}
struct info
{
    int y;
    int x;
    int d;
    int next;
    int pre;
} horse[11];

int dir[5][2] = {{0, 0}, {0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int change_dir[5] = {0, 2, 1, 4, 3};
int ans;

void blue(int num)
{
    horse[num].d = change_dir[horse[num].d];
    int dy = horse[num].y + dir[horse[num].d][0];
    int dx = horse[num].x + dir[horse[num].d][1];
    if (map[dy][dx] == 2 || !inside(dy, dx))
        return;
    horse[num].y = dy;
    horse[num].x = dx;
}

int horse_size(int num)
{
    int ret = 1;
    while (1)
    {
        if (horse[num].next == 0)
            break;
        num = horse[num].next;
        ret++;
    }
    return (ret);
}

void red(int num)
{
    vector<int> vec;
    vec.push_back(num);

    while (1)
    {
        if (horse[num].next == 0)
            break;
        num = horse[num].next;
        vec.push_back(num);
    }
    horse[vec.size() - 1].pre = 0;
    for (int i = vec.size() - 1; i > 0; i--)
    {
        horse[vec[i]].next = vec[i - 1];
    }
    horse[vec[0]].next = 0;
    h_map[horse[num].y][horse[num].x] = vec[vec.size() - 1];
}

int calc(int num)
{
    int ret = 1;
    while (1)
    {
        if (horse[num].next == 0)
            return ret;
        ret++;
        num = horse[num].next;
    }
}

void move()
{
    while (1)
    {
        if (ans > 1000)
        {
            ans = -1;
            return;
        }
        for (int i = 1; i <= k; i++)
        {
            if (horse[i].pre == 0)
            {
                info cur = horse[i];
                if (horse_size(i) >= 4)
                    return;
                int dy = cur.y + dir[cur.d][0];
                int dx = cur.x + dir[cur.d][1];
                h_map[cur.y][cur.x] = 0;

                if (!inside(dy, dx) || map[dy][dx] == 2)
                {
                    blue(i);
                }
                else
                {
                    if (map[dy][dx] == 1)
                        red(i);
                    else
                    {
                        horse[i].y = dy;
                        horse[i].x = dx;
                    }
                }
            }
        }
        ans++;
        for (int i = 1; i <= k; i++)
        {
            if (calc(i) >= 4)
                return;
        }
    }
}

int main(void)
{
    cin.tie(0);
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
        horse[i].y = y;
        horse[i].x = x;
        horse[i].d = d;
        horse[i].next = 0;
        horse[i].pre = 0;
        h_map[y][x] = i;
    }

    move();
    cout << ans;
}