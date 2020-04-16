#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int n, k;
int ans;
int cnt;
vector<int> vec[2];
int dir[2][2] = {{0, -1}, {0, 1}};

typedef struct info
{
    int y, x;
} info;

int BFS()
{
    info data;
    int cnt = 0;
    bool check[2][100001];
    memset(check, false, sizeof(check));
    data.y = 0;
    data.x = 0;
    queue<info> que;
    que.push(data);

    while (!que.empty())
    {
        int SIZE = que.size();
        for (int i = 0; i < SIZE; i++)
        {
            info cur = que.front();
            if (cur.x >= n)
                return 1;
            que.pop();
            for (int j = 0; j < 2; j++)
            {
                int dy = cur.y + dir[j][0];
                int dx = cur.x + dir[j][1];
                if (dx >= n)
                    return 1;
                if (cnt < dx && vec[dy][dx] != 0 && check[dy][dx] == false)
                {
                    check[dy][dx] = true;
                    info next;
                    next.y = dy;
                    next.x = dx;
                    que.push(next);
                }
            }
            int dy;
            if (cur.y == 0)
                dy = 1;
            else
                dy = 0;
            int dx = cur.x + k;
            if (dx >= n)
                return 1;
            if (cnt < dx && vec[dy][dx] != 0 && check[dy][dx] == false)
            {
                check[dy][dx] = true;
                info next;
                next.y = dy;
                next.x = dx;
                que.push(next);
            }
        }
        cnt++;
    }
    return 0;
}

void Input()
{
    string str;
    for (int i = 0; i < 2; i++)
    {
        cin >> str;
        for (int j = 0; j < str.size(); j++)
            vec[i].push_back(str[j] - '0');
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    Input();
    cout << BFS();
}