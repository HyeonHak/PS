#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int t, n, ans;
bool visit[100001];
bool iscycle[100001];

vector<int> vec[100001];

void Input()
{
	int value;

	cin >> n;
	for (int j = 1; j <= n; j++)
	{
		cin >> value;
		vec[j].push_back(value);
	}
}

bool DFS(int num, int start)
{
	if (visit[num] == true && num == start)
	{
		iscycle[num] = true;
		return true;
	}
	visit[num] = true;
	if (!visit[vec[num][0]])
	{
		if (DFS(vec[num][0], start) == true)
		{
			iscycle[num] = true;
			return true;
		}
		else
		{
			iscycle[num] = false;
			return false;
		}
	}
}

void Solve()
{
	for (int i = 1; i <= n; i++)
	{
		if (!iscycle[i])
			DFS(i, i);
	}
}

void Reset()
{
	ans = 0;
	for (int i = 0; i <= n; i++)
	{
		vec[i].clear();
		visit[i] = false;
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	for (int i = 1; i < t; i++)
	{
		Input();
		Solve();
		cout << endl;
		for (int i = 1; i <= n; i++)
			cout << iscycle[i] << " ";
		cout << endl;
		return 0;
		cout << ans;
		Reset();
	}
}
