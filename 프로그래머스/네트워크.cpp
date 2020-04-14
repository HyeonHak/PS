#include <string>
#include <iostream>
#include <vector>

using namespace std;

int check[201][201];
int cnt = 0;

void DFS(int n, vector<vector<int>> &computers, int idx)
{
    for (int i = 0; i < computers[idx].size(); i++)
    {
        if (i == idx)
            continue;
        if (computers[idx][i] == 1 && check[idx][i] == 0)
        {
            check[idx][i] = cnt;
            check[i][idx] = cnt;
            DFS(n, computers, i);
        }
    }
}

int solution(int n, vector<vector<int>> computers)
{
    int answer = 0;
    for (int i = 0; i < computers.size(); i++)
    {
        int tmp_cnt = 0;
        for (int j = 0; j < computers[i].size(); j++)
        {
            if (i == j)
            {
                tmp_cnt++;
                continue;
            }
            if (computers[i][j] == 1 && check[i][j] == 0)
            {
                cnt++;
                check[i][j] = cnt;
                check[j][i] = cnt;
                DFS(n, computers, j);
            }
            if (computers[i][j] == 1)
            {
                tmp_cnt++;
            }
        }
        if (tmp_cnt == 1)
        {
            cout << i << endl;
            cnt++;
        }
    }
    answer = cnt;
    return answer;
}