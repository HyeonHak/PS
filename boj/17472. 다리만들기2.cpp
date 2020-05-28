#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

int n, m;
int ans = 987654321;
int map[12][12];
int visit[12][12];
int visited[101][101];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
bool candi_visit[101];
vector<int> arr;

vector<int> vec[101];
typedef struct info
{
    int y;
    int x;
} info;
info input;
queue<info> que;
vector<info> candidate;

bool inside(int y, int x)
{
    return y >= 0 && y < n && x >= 0 && x < m;
}

void Input()
{
    cin >> n >> m;
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < m; x++)
        {
            cin >> map[y][x];
        }
    }
}

void DFS(int y, int x, int cnt)
{
    visit[y][x] = cnt;
    input.y = y;
    input.x = x;
    que.push(input);
    while (!que.empty())
    {
        int SIZE = que.size();
        for (int i = 0; i < SIZE; i++)
        {
            info cur = que.front();
            que.pop();
            for (int j = 0; j < 4; j++)
            {
                int dy = cur.y + dir[j][0];
                int dx = cur.x + dir[j][1];
                if (!inside(dy, dx))
                    continue;
                if (visit[dy][dx] != 0)
                    continue;
                if (map[dy][dx] == 1)
                {
                    visit[dy][dx] = cnt;
                    info next;
                    next.y = dy;
                    next.x = dx;
                    que.push(next);
                }
            }
        }
    }
}

void dis_cnt(int y, int x)
{
    for (int i = 0; i < 4; i++)
    {
        int dy = y;
        int dx = x;
        int cnt = 0;

        while (1)
        {
            dy += dir[i][0];
            dx += dir[i][1];
            if (!inside(dy, dx))
                break;
            if (visit[dy][dx] == visit[y][x])
                break;
            if (map[dy][dx] != 0 && visit[dy][dx] != visit[y][x])
            {
                if (cnt >= 2)
                {
                    if (visited[visit[y][x]][visit[dy][dx]] == 0 || visited[visit[y][x]][visit[dy][dx]] > cnt)
                    {
                        visited[visit[y][x]][visit[dy][dx]] = cnt;
                        visited[visit[dy][dx]][visit[y][x]] = cnt;
                    }
                }
                break;
            }
            cnt++;
        }
    }
}

void check_dis(int cnt)
{
    memset(visited, 0, sizeof(visited));

    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < m; x++)
        {
            if (visit[y][x] != 0)
            {
                dis_cnt(y, x);
            }
        }
    }

    for (int y = 1; y < cnt; y++)
    {
        for (int x = 1; x < cnt; x++)
        {
            if (y == x)
                continue;
            if (visited[y][x] != 0)
            {
                vec[y].push_back(x);
                cout << y << " " << x << " " << visited[y][x] << endl;
            }
        }
    }
}

void DFS_connect(int num, int cnt, int value)
{
}

void map_num()
{
    int cnt = 1;
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < m; x++)
        {
            if (map[y][x] == 1 && !visit[y][x])
            {
                DFS(y, x, cnt);
                cnt++;
            }
        }
    }
    check_dis(cnt);
    cout << endl;
    for (int i = 1; i < cnt; i++)
    {
        for (int j = 0; j < vec[i].size(); j++)
        {
            cout << vec[i][j] << " ";
            input.y = i;
            input.x = vec[i][j];
            candidate.push_back(input);
        }
        cout << endl;
    }
}

void Solve()
{
    map_num();
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    Input();
    Solve();
    if (ans == 987654321)
        ans = -1;
    cout << ans;
}
