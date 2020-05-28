#include <iostream>
#include <algorithm>
#include <math.h>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
int n;
int ans = 987654321;
int visit[12];
int arr[13];

typedef struct info
{
	int score;
	vector<int> lc;
} info;
info input[13];

void Input()
{
	int cnt;
	int value;

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> input[i].score;
	for (int i = 1; i <= n; i++)
	{
		cin >> cnt;
		for (int j = 0; j < cnt; j++)
		{
			cin >> value;
			input[i].lc.push_back(value);
		}
	}
}

bool check()
{
	queue<int> que;
	memset(visit, 0, sizeof(visit));
	bool A = false;
	bool B = false;
	for (int i = 1; i <= n; i++)
	{
		if (arr[i] && !A)
		{
			visit[i] = true;
			A = true;
			que.push(i);
			while (!que.empty())
			{
				int SIZE = que.size();
				for (int j = 0; j < SIZE; j++)
				{
					int cur = que.front();
					que.pop();
					for (int k = 0; k < input[cur].lc.size(); k++)
					{
						if (!visit[input[cur].lc[k]] && arr[i] == arr[input[cur].lc[k]])
						{
							visit[input[cur].lc[k]] = true;
							que.push(input[cur].lc[k]);
						}
					}
				}
			}
		}
		else if (!arr[i] && !B)
		{
			B = true;
			visit[i] = true;
			que.push(i);
			while (!que.empty())
			{
				int SIZE = que.size();
				for (int j = 0; j < SIZE; j++)
				{
					int cur = que.front();
					que.pop();
					for (int k = 0; k < input[cur].lc.size(); k++)
					{
						if (!visit[input[cur].lc[k]] && arr[i] == arr[input[cur].lc[k]])
						{
							visit[input[cur].lc[k]] = true;
							que.push(input[cur].lc[k]);
						}
					}
				}
			}
		}
	}

	for (int i = 1; i <= n; i++)
		if (!visit[i])
			return false;
	return true;
}

void calc()
{
	int ret = 0;
	for (int i = 1; i <= n; i++)
	{
		if (arr[i] == 0)
			ret += input[i].score;
		else
			ret -= input[i].score;
	}
	if (abs(ret) < ans)
		ans = abs(ret);
}

void DFS(int depth, int zcnt, int ocnt)
{
	if (depth == n + 1)
	{
		if (zcnt == 0 || ocnt == 0)
			return;

		if (check())
			calc();
		return;
	}
	arr[depth] = 1;
	DFS(depth + 1, zcnt, ocnt + 1);
	arr[depth] = 0;
	DFS(depth + 1, zcnt + 1, ocnt);
}

void Solve()
{
	DFS(1, 0, 0);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	Input();
	Solve();
	if (ans == 987654321)
		ans = -1;
	cout << ans;
}
