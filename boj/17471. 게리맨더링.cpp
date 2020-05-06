#include <iostream>
#include <limits.h>
#include <cstring>
#include <vector>
using namespace std;

int n;
int input;
int ans = INT_MAX;
vector<int> vec[11];
bool visit[13];
bool check[13];
int A_cnt = 0;
int B_cnt = 0;
int check_A = 0;
int check_B = 0;
int val[13];
bool team_A[13];
bool team_B[13];

void DFS(int cur, int team)
{
    if (team == 0)
        check_A++;
    else
        check_B++;

    visit[cur] = true;
    for (int i = 0; i < vec[cur].size(); i++)
    {
        if (team == 0)
        {
            if (team_A[vec[cur][i]] && visit[vec[cur][i]] == false)
            {
                DFS(vec[cur][i], team);
            }
        }
        else
        {
            if (team_B[vec[cur][i]] && visit[vec[cur][i]] == false)
            {
                DFS(vec[cur][i], team);
            }
        }
    }
}

void calc()
{
    int A_val = 0;
    int B_val = 0;
    check_A = 1;
    check_B = 1;
    for (int i = 1; i <= n; i++)
    {
        if (A_val != 0 && B_val != 0)
            break;
        if (team_A[i] == true && A_val == 0)
            A_val = i;
        else if (team_B[i] == true && B_val == 0)
            B_val = i;
    }

    visit[A_val] = true;
    visit[B_val] = true;

    for (int i = 0; i < vec[A_val].size(); i++)
    {
        if (team_A[vec[A_val][i]] == true && visit[vec[A_val][i]] == false)
        {
            DFS(vec[A_val][i], 0);
        }
    }
    if (check_A != A_cnt)
        return;

    for (int i = 0; i < vec[B_val].size(); i++)
    {
        if (team_B[vec[B_val][i]] == true && visit[vec[B_val][i]] == false)
        {
            DFS(vec[B_val][i], 1);
        }
    }
    if (check_B != B_cnt)
        return;
    int ret = 0;
    for (int i = 1; i <= n; i++)
    {
        if (team_A[i])
            ret += val[i];
        else
            ret -= val[i];
    }
   
    if (ans > abs(ret))
        ans = abs(ret);
}

void DFS(int cur, int depth, int start)
{
    if (cur == depth)
    {
        A_cnt = 0;
        B_cnt = 0;
        memset(visit, false, sizeof(visit));
        for (int i = 1; i <= n; i++)
        {
            if (team_A[i] == false)
            {
                team_B[i] = true;
                B_cnt++;
            }
            else
            {
                team_B[i] = false;
                A_cnt++;
            }
        }
        calc();
        return;
    }
    for (int i = start; i <= n; i++)
    {
        if (check[i] == false)
        {
            check[i] = true;
            team_A[i] = true;
            DFS(cur + 1, depth, i);
            team_A[i] = false;
            check[i] = false;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> input;
        val[i] = input;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> input;
        for (int j = 0; j < input; j++)
        {
            int value;
            cin >> value;
            vec[i].push_back(value);
        }
    }
    for (int i = 1; i < n; i++)
        DFS(0, i, 1);
    if (ans == INT_MAX)
        ans = -1;
    cout << ans;
}