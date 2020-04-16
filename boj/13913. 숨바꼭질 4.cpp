#include <iostream>
#include <queue>
using namespace std;

int n, k;
int visit[200003];
int dir[2] = {-1, 1};

queue<int> que;
vector<int> ans;
int time_;

int inside(int x)
{
    return x >= 0 && x <= 200002;
}

void calc()
{
    int value = k;
    ans.push_back(value);
    while (value != n)
    {
        ans.push_back(visit[value]);
        value = visit[value];
    }
}

void BFS()
{

    que.push(n);
    visit[n] = n;

    while (!que.empty())
    {
        int SIZE = que.size();
        for (int i = 0; i < SIZE; i++)
        {
            int cur = que.front();
            que.pop();
            if (cur == k)
            {
                calc();
                return;
            }
            for (int j = 0; j < 2; j++)
            {
                int next = cur + dir[j];
                if (inside(next) && visit[next] == -1)
                {
                    visit[next] = cur;
                    que.push(next);
                }
            }
            int next = cur * 2;
            if (inside(next) && visit[next] == -1)
            {
                visit[next] = cur;
                que.push(next);
            }
        }
        time_++;
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i <= 200002; i++)
        visit[i] = -1;
    BFS();
    cout << time_ << "\n";
    while (!ans.empty())
    {
        cout << ans.back() << " ";
        ans.pop_back();
    }
}