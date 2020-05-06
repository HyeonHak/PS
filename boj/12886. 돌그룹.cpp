#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int A, B, C;
bool visit[1001][1001][1001];
typedef struct info
{
    int a;
    int b;
    int c;
} info;
queue<info> que;

void Insert(int a, int b, int c, int flag)
{
    if (flag == 0)
    {
        if (b > c)
        {
            b = b - c;
            c = c + c;
        }
        else
        {
            c = c - b;
            b = b + b;
        }
    }
    else if (flag == 1)
    {
        if (a > c)
        {
            a = a - c;
            c = c + c;
        }
        else
        {
            c = c - a;
            a = a + a;
        }
    }
    else
    {
        if (a > b)
        {
            a = a - b;
            b = b + b;
        }
        else
        {
            b = b - a;
            a = a + a;
        }
    }
    if (visit[a][b][c] == false)
    {
        visit[a][b][c] = true;
        que.push({a, b, c});
    }
}

int BFS()
{
    info data;
    data = {A, B, C};
    visit[A][B][C] = true;

    que.push(data);
    while (!que.empty())
    {
        int SIZE = que.size();
        for (int i = 0; i < SIZE; i++)
        {
            info cur = que.front();
            if (cur.a == cur.b && cur.a == cur.c)
                return 1;
            que.pop();
            if (cur.a != cur.b)
                Insert(cur.a, cur.b, cur.c, 2);
            if (cur.a != cur.c)
                Insert(cur.a, cur.b, cur.c, 1);
            if (cur.b != cur.c)
                Insert(cur.a, cur.b, cur.c, 0);
        }
    }
    return 0;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> A >> B >> C;
    cout << BFS();
    return (0);
}