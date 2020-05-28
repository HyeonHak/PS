#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int ans = 987654321;
int n;
int value[12];
bool visit[12];

vector<int> a, b;
vector<int> vec[12];

void Input()
{
	int input;
	int input_2;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> value[i];
	for (int i = 1; i <= n; i++)
	{
		cin >> input;
		for (int j = 0; j < input; j++)
		{
			cin >> input_2;
			vec[i].push_back(input_2);
		}
	}
	return;
}

bool check()
{
	bool visited[12];
	memset(visited, 0, sizeof(visited));
	queue<int> que;
	que.push(1);
	visited[1] = true;

	while (!que.empty())
	{
		int SIZE = que.size();
		for (int i = 0; i < SIZE; i++)
		{
			int cur = que.front();
			que.pop();
			for (int j = 0; j < vec[cur].size(); j++)
			{
				int next = vec[cur][j];
				if (!visited[next] && visit[cur] == visit[next])
				{
					visited[next] = true;
					que.push(next);
				}
			}
		}
	}
	int next_value;
	for (int i = 2; i <= n; i++)
	{
		if (visit[1] != visit[i])
		{
			next_value = i;
			break;
		}
	}

	que.push(next_value);
	visited[next_value] = true;
	while (!que.empty())
	{
		int SIZE = que.size();
		for (int i = 0; i < SIZE; i++)
		{
			int cur = que.front();
			que.pop();
			for (int j = 0; j < vec[cur].size(); j++)
			{
				int next = vec[cur][j];
				if (!visited[next] && visit[next_value] == visit[next])
				{
					visited[next] = true;
					que.push(next);
				}
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (!visited[i])
			return false;
	}
	return true;
}

void DFS(int depth, int a_cnt, int start)
{
	if (depth == a_cnt)
	{
		for (int i = 1; i <= n; i++)
		{
			if (!visit[i])
				b.push_back(i);
		}
		if (check())
		{
			int tmp = 0;
			int tmp_b = 0;
			for (int i = 0; i < a.size(); i++)
				tmp += value[a[i]];
			for (int i = 0; i < b.size(); i++)
				tmp_b += value[b[i]];
			tmp = abs(tmp - tmp_b);
			if (tmp < ans)
				ans = tmp;
		}
		b.clear();
		return;
	}

	for (int i = start; i <= n; i++)
	{
		if (!visit[i])
		{
			visit[i] = true;
			a.push_back(i);
			DFS(depth + 1, a_cnt, i);
			a.pop_back();
			visit[i] = false;
		}
	}
}

void Solve()
{
	for (int i = 1; i < n; i++)
		DFS(0, i, 0);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	Input();
	Solve();
	if (ans == 987654321)
		ans = -1;
	cout << ans;
}
