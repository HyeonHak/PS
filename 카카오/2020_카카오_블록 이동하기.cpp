#include <string>
#include <queue>
#include <vector>

using namespace std;
bool visit[101][101][4];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int N;

typedef struct info
{
    int y;
    int x;
    int dy;
    int dx;
} info;

int inside(int y, int x)
{
    return y >= 0 && y < N && x >= 0 && x < N;
}

bool ans_check(info data)
{
    if ((data.x == N - 1 && data.y == N - 1) || (data.dy == N - 1 && data.dx == N - 1))
        return true;
    return false;
}

int BFS(vector<vector<int>> &board)
{
    int ret = 0;
    info input;
    queue<info> que;
    input = {0, 0, 0, 1};
    que.push(input);
    while (!que.empty())
    {
        int SIZE = que.size();
        for (int i = 0; i < SIZE; i++)
        {
            info cur = que.front();
            if (ans_check(cur))
                return ret;
            ret++;
            que.pop();
            for (int j = 0; j < 4; j++)
            {
                int x1 = cur.x + dir[j][0];
                int y1 = cur.y + dir[j][1];
                int x2 = cur.dx = dir[j][0];
                int y2 = cur.dy + dir[j][1];
                if (inside(y1, x1) && inside(y2, x2) && board[y1][x1] == 0 && board[y2][x2] == 0)
                {
                    info next;
                    if (x1 > x2 && visit[y1][x1][2] == false && visit[y2][x2][3] == false)
                    {
                        visit[y1][x1][2] = true;
                        visit[y2][x2][3] = true;
                        next = {y1, x1, y2, x2};
                        que.push(next);
                    }
                    else if (x1 < x2 && visit[y1][x1][3] == false && visit[y2][x2][2] == false)
                    {
                        visit[y1][x1][3] = true;
                        visit[y2][x2][2] = true;
                        next = {y1, x1, y2, x2};
                        que.push(next);
                    }
                }
            }

            if (cur.x == cur.dx)
            {
                if (cur.y > cur.dy)
                {
                    if (board[cur.dy][cur.dx - 1] == 0 && board[cur.y][cur.x - 1] == 0 && visit[cur.y][cur.x - 1][3] == false && visit[cur.y][cur.x][2] == false)
                    {
                        visit[cur.y][cur.x][2] = true;
                        visit[cur.y][cur.x - 1][3] = true;
                        que.push({cur.y, cur.x, cur.y, cur.x - 1});
                    }
                    if (board[cur.dy][cur.dx + 1] == 0 && board[cur.y][cur.x + 1] == 0 && visit[cur.y][cur.x + 1][2] == false && visit[cur.y][cur.x][3] == false)
                    {
                        visit[cur.y][cur.x][3] = true;
                        visit[cur.y][cur.x - 1][2] = true;
                        que.push({cur.y, cur.x, cur.y, cur.x + 1});
                    }
                }
                else
                {
                    if (board[cur.y][cur.x - 1] == 0 && board[cur.dy][cur.dx - 1] == 0 && visit[cur.y][cur.x][2] == false && visit[cur.y][cur.x - 1][3] == false)
                    {
                        visit[cur.y][cur.x][2] = true;
                        visit[cur.y][cur.x - 1][3] = true;
                        que.push({cur.y, cur.x, cur.y, cur.x - 1});
                    }
                    if (board[cur.y][cur.x + 1] == 0 && board[cur.dy][cur.dx + 1] == 0 && visit[cur.y][cur.x + 1][2] == false && visit[cur.y][cur.x][3] == false)
                    {
                        visit[cur.y][cur.x][3] = true;
                        visit[cur.y][cur.x - 1][2] = true;
                        que.push({cur.y, cur.x, cur.y, cur.x + 1});
                    }
                }
            }
            else
            {
                if (cur.x > cur.dx)
                {
                    if (board[cur.dy - 1][cur.dx] == 0 && board[cur.y - 1][cur.x] == 0 && visit[cur.y][cur.x][0] == false && visit[cur.y - 1][cur.x][1] == false)
                    {
                        visit[cur.y][cur.x][0] = true;
                        visit[cur.y - 1][cur.x][1] = true;
                        que.push({cur.y, cur.x, cur.y - 1, cur.x});
                    }
                    if (board[cur.dy + 1][cur.dx] == 0 && board[cur.y + 1][cur.x] == 0 && visit[cur.y][cur.x][1] == false && visit[cur.y + 1][cur.x][0] == false)
                    {
                        visit[cur.y + 1][cur.x][0] = true;
                        visit[cur.y][cur.x][1] = true;
                        que.push({cur.y, cur.x, cur.y + 1, cur.x});
                    }
                }
            }
        }
    }
}

int solution(vector<vector<int>> board)
{
    int answer = 0;
    N = board.size();
    visit[0][0][3] = visit[0][1][2] = true;
    BFS(board);
    return answer;
}