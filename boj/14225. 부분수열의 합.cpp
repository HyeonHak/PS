#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int n, input;
vector<int> vec;
bool check[2000001];
bool visit[21];
int arr[21];

void DFS(int depth, int cur, int start)
{
    if (depth == cur)
    {
        int cnt = 0;
        for (int i = 0; i < cur; i++)
            cnt += arr[i];
        check[cnt] = true;
        return;
    }

    for (int i = start; i < vec.size(); i++)
    {
        if (visit[i] == false)
        {
            visit[i] = true;
            arr[cur] = vec[i];
            DFS(depth, cur + 1, i);
            visit[i] = false;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        vec.push_back(input);
    }

    for (int i = 1; i <= n; i++)
    {
        DFS(i, 0, 0);
        memset(visit, false, sizeof(visit));
    }

    for (int i = 1; i <= 2000000; i++)
    {
        if (check[i] == false)
        {
            cout << i;
            return (0);
        }
    }
}