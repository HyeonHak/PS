#include <iostream>
#include <limits.h>
#include <cstring>
#include <vector>
using namespace std;

int N, input;
int ans = INT_MAX;
vector<int> city[11];
bool visit[11][11];
bool check[11];
int tmp_cnt;

void DFS(int start, int cur, int cnt)
{
    if (start == cur && cnt == N)
    {
        if (ans > tmp_cnt)
            ans = tmp_cnt;
        return;
    }
    for (int i = 1; i <= N; i++)
    {
        if (i == cur)
            continue;
        if (check[i] == false && city[cur][i] > 0)
        {
            check[i] = true;
            tmp_cnt += city[cur][i];
            DFS(start, i, cnt + 1);
            tmp_cnt -= city[cur][i];
            check[i] = false;
        }
        else if(i == start && cnt == N - 1 && city[cur][i] > 0)
        {
            check[i] = true;
            tmp_cnt += city[cur][i];
            DFS(start, i, cnt + 1);
            tmp_cnt -= city[cur][i];
            check[i] = false;
        }
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        city[i].push_back(0);
        for (int j = 0; j < N; j++)
        {
            cin >> input;
            city[i].push_back(input);
        }
    }

    for (int i = 1; i <= N; i++)
    {
        check[i] = true;
        DFS(i, i, 0);
        check[i] = false;
    }
    cout << ans;
    return (0);
}