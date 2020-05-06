#include <string>
#include <cstring>
#include <vector>
#include <iostream>

using namespace std;

int arr[9];
int weak_check[16];
int install[16];
bool visit[201];
int flag = 0;
int answer = 0;
int N;
void select(int depth, vector<int> &dist)
{
    int SIZE = dist.size() - 1;
    cout << "select : " << depth << endl;
    for (int i = 0; i < depth; i++)
    {
        arr[i] = SIZE--;
        cout << arr[i] << " ";
    }
    cout << endl;
}

void calc(int depth, vector<int> &weak, vector<int> &dist)
{
    cout << "TEST" << weak[install[0]] << endl;
    for (int i = 0; i < depth; i++)
    {
        visit[weak[install[i]]] = true;
        cout << weak[install[i]] << " ";

        int value = (weak[install[i]] + dist[arr[i]]) % N;
        for (int j = install[i]; j < weak.size(); j++)
        {
            if (value > weak[j])
                visit[weak[j]] = true;
            else
                break;
        }
    }
}

void solve(int depth, int cnt, vector<int> &weak, vector<int> &dist, int start)
{
    if (flag == 1)
        return;
    if (cnt == depth)
    {
        memset(visit, false, sizeof(visit));
        int tmp = 0;
        calc(depth, weak, dist);
        cout << "checking\n";
        for (int j = 0; j < weak.size(); j++)
        {
            cout << visit[weak[j]];
        }
        cout << endl;
        for (int j = 0; j < weak.size(); j++)
        {
            if (visit[weak[j]] == false)
            {
                tmp = 1;
                break;
            }
        }
        if (tmp == 0)
        {
            answer = depth;
            flag = 1;
        }
        return;
    }

    for (int i = 0; i < weak.size(); i++)
    {
        if (weak_check[i] == false)
        {
            weak_check[i] = true;
            install[depth] = i;
            solve(depth + 1, cnt, weak, dist, i);
            weak_check[i] = false;
        }
    }
}

int solution(int n, vector<int> weak, vector<int> dist)
{
    N = n;
    for (int i = 1; i <= dist.size(); i++)
    {
        memset(visit, false, sizeof(visit));
        select(i, dist);
        cout << "solve : \n";
        solve(0, i, weak, dist, 0);
    }
    answer = -1;
    return answer;
}