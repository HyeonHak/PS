#include <iostream>
#include <queue>
using namespace std;
int S;
int ans;
bool visit[2020][2020];

typedef struct info
{
    int display;
    int board;
} info;

void BFS()
{
    queue<info> que;
    info data;

    que.push({1, 0});

    while (!que.empty())
    {
        int SIZE = que.size();
        for (int i = 0; i < SIZE; i++)
        {
            info cur = que.front();
            if (cur.display == S)
                return;
            que.pop();
            info next;
            if (visit[cur.display][cur.display] == false)
            {
                next.display = cur.display;
                next.board = cur.display;
                visit[next.display][next.board] = true;
                que.push(next);
            }
            if (cur.display + cur.board <= 2000 && cur.board != 0 && visit[cur.display + cur.board][cur.board] == false)
            {
                next.display = cur.display + cur.board;
                next.board = cur.board;
                visit[next.display][next.board] = true;
                que.push(next);
            }
            if (cur.display - 1 >= 0 && visit[cur.display - 1][cur.board] == false)
            {
                next.display = cur.display - 1;
                next.board = cur.board;
                que.push(next);
                visit[next.display][next.board] = true;
            }
        }
        ans++;
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> S;
    visit[1][0] = true;
    BFS();
    cout << ans;
}