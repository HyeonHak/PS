#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct info
{
    int y;
    int x;
} info;
vector<info> vec;

int map[10][10];

int map_number(int y,int x)
{
    
}

int horizen(int y)
{
    bool visit[10];
    fill(visit, visit + 9, false);
    for (int x = 1; x <= 9; x++)
    {
        if (map[y][x] == 0)
            continue;
        visit[map[y][x]]++;
        if (visit[map[y][x]] > 1)
            return -1;
    }
    return 1;
}

int sujik(int x)
{
    bool visit[10];
    fill(visit, visit + 9, false);
    for (int y = 1; y <= 9; y++)
    {
        if (map[y][x] == 0)
            continue;
        visit[map[y][x]]++;
        if (visit[map[y][x]] > 1)
            return -1;
    }
    return 1;
}

int square(int cur)
{
    bool visit[10];
    fill(visit, visit + 9, false);
    
    return 1;
}

void DFS(int depth, int cur)
{
    if (depth == cur)
    {
    }

    for (int i = 1; i <= 9; i++)
    {
        map[vec[cur].y][vec[cur].x] = i;
        if (horizen(vec[cur].y) && sujik(vec[cur].x) && square(cur))
        {
            DFS(depth, cur + 1);
            map[vec[cur].y][vec[cur].x] = 0;
        }
        else
            map[vec[cur].y][vec[cur].x] = 0;
    }
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    for (int y = 1; y <= 9; y++)
    {
        for (int x = 1; x <= 9; x++)
        {
            cin >> map[y][x];
            if (map[y][x] == 0)
                vec.push_back({y, x});
        }
    }
    DFS(vec.size(), 0);
}