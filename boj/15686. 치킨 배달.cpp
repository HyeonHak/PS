#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int map[51][51];
int ans = 987654321;

typedef struct info
{
	int y;
	int x;
} info;
info input;
vector<info> candidate;
vector<info> home;
vector<int> vec;
bool visit[2511];

void Input()
{
	cin >> n >> m;

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			cin >> map[y][x];
			if (map[y][x] == 2)
			{
				input.y = y;
				input.x = x;
				candidate.push_back(input);
			}
			else if (map[y][x] == 1)
			{
				input.y = y;
				input.x = x;
				home.push_back(input);
			}
		}
	}
}

int dis(int y, int x, int dy, int dx)
{
	return abs(y - dy) + abs(x - dx);
}

void calc()
{
	int value = 0;

	for (int i = 0; i < home.size(); i++)
	{
		int tmp = 987654321;
		for (int j = 0; j < vec.size(); j++)
		{
			tmp = min(tmp, dis(home[i].y, home[i].x, candidate[vec[j]].y, candidate[vec[j]].x));
		}
		value += tmp;
	}
	if (value < ans)
		ans = value;
}

void DFS(int depth, int start)
{
	if (depth == m)
	{
		calc();
		return;
	}

	for (int i = start; i < candidate.size(); i++)
	{
		if (!visit[i])
		{
			visit[i] = true;
			vec.push_back(i);
			DFS(depth + 1, i);
			vec.pop_back();
			visit[i] = false;
		}
	}
}

void Solve()
{
	DFS(0, 0);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	Input();
	Solve();
	cout << ans;
}
