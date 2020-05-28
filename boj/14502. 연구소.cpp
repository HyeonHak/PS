#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;

int n, m;
int ans = 0;
int map[10][10];
int ori_map[10][10];
bool visit[10][10];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
typedef struct info
{
	int y;
	int x;
} info;
info input;
vector<info> vec;
vector<int> candidate;
vector<info> virus;
bool vec_visit[101];
bool inside(int y, int x)
{
	return y >= 0 && y < n && x >= 0 && x < m;
}

void Input()
{
	cin >> n >> m;
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < m; x++)
		{
			cin >> map[y][x];
			ori_map[y][x] = map[y][x];
			if (map[y][x] == 0)
			{
				input.y = y;
				input.x = x;
				vec.push_back(input);
			}
			else if (map[y][x] == 2)
			{
				input.y = y;
				input.x = x;
				virus.push_back(input);
			}
		}
	}
}

void BFS()
{
	queue<info> que;
	for (int i = 0; i < virus.size(); i++)
	{
		info value = virus[i];
		que.push(value);
	}

	while (!que.empty())
	{
		int SIZE = que.size();
		for (int i = 0; i < SIZE; i++)
		{
			info cur = que.front();
			que.pop();
			for (int j = 0; j < 4; j++)
			{
				int dy = cur.y + dir[j][0];
				int dx = cur.x + dir[j][1];
				if (!inside(dy, dx))
					continue;
				if (map[dy][dx] == 2 || map[dy][dx] == 1)
					continue;
				map[dy][dx] = 2;
				input.y = dy;
				input.x = dx;
				que.push(input);
			}
		}
	}
	int cnt = 0;
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < m; x++)
		{
			if (map[y][x] == 0)
				cnt++;
		}
	}
	if (cnt > ans)
		ans = cnt;
}

void calc()
{
	for (int i = 0; i < candidate.size(); i++)
	{
		info cur = vec[candidate[i]];
		map[cur.y][cur.x] = 1;
	}
	BFS();
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < m; x++)
		{
			map[y][x] = ori_map[y][x];
		}
	}
}

void DFS(int depth, int start)
{
	if (depth == 3)
	{
		calc();
		return;
	}
	for (int i = start; i < vec.size(); i++)
	{
		if (!vec_visit[i])
		{
			vec_visit[i] = true;
			candidate.push_back(i);
			DFS(depth + 1, i);
			vec_visit[i] = false;
			candidate.pop_back();
		}
	}
}

void Solve()
{
	DFS(0, 0);
}

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	Input();
	Solve();
	cout << ans;
}
