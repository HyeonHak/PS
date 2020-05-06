#include <iostream>
#include <queue>
using namespace std;
int n, m;
int map[101][101];
int ans, to_, from_;
queue<int> que;
int visit[101];
int bridge[101];
int snake[101];
void BFS()
{
    que.push(1);
    visit[1] = true;

    while (!que.empty())
    {
        int SIZE = que.size();
        for (int i = 0; i < SIZE; i++)
        {
            int cur = que.front();
            if (cur == 100)
                return;
            que.pop();
            for (int j = 1; j <= 6; j++)
            {
                int dy = cur + j;
                if (visit[dy] == false && dy <= 100)
                {
                    if (snake[dy] != 0 || bridge[dy] != 0)
                    {
                        if (snake[dy] != 0 && visit[snake[dy]] == false)
                        {
                            visit[dy] = true;
                            visit[snake[dy]] = true;
                            que.push(snake[dy]);
                        }
                        else if (bridge[dy] != 0 && visit[bridge[dy]] == false)
                        {
                            visit[dy] = true;
                            visit[bridge[dy]] = true;
                            que.push(bridge[dy]);
                        }
                    }
                    else
                    {
                        visit[dy] = true;
                        que.push(dy);
                    }
                }
            }
        }
        ans++;
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> to_ >> from_;
        bridge[to_] = from_;
    }
    for (int j = 0; j < m; j++)
    {
        cin >> to_ >> from_;
        snake[to_] = from_;
    }
    BFS();
    cout << ans;
}