//11 : 52

#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
typedef struct info
{
	int y;
	int x;
} info;
int n, m;

bool inside(int y, int x)
{
	return y >= 0 && y < n && x >= 0 && x < n;
}
info input;
vector<info> candidate;
vector<int> vec;

int check[51][51];
bool visit[2501];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int map[51][51];
int wall_cnt = 0;
int ans = 987654321;
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
				wall_cnt++;
		}
	}
}

void print()
{
	cout << endl;
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			cout << check[y][x] << " ";
		}
		cout << endl;
	}
}

void calc()
{
	memset(check, 0, sizeof(check));

	int Space = n * n - candidate.size() - wall_cnt;
	int cnt = 0;
	queue<info> que;

	for (int i = 0; i < m; i++)
	{
		check[candidate[vec[i]].y][candidate[vec[i]].x] = -1;
		que.push(candidate[vec[i]]);
	}
	if (Space == 0)
	{
		ans = 0;
		return;
	}
	while (!que.empty())
	{
		int SIZE = que.size();
		cnt++;

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
				if (check[dy][dx] != 0)
					continue;
				if (map[dy][dx] == 1)
					continue;
				check[dy][dx] = cnt;
				info next = {dy, dx};
				que.push(next);
				if (map[dy][dx] == 0)
					Space--;
			}
		}
		//print();

		if (Space == 0)
			break;
	}

	if (Space == 0)
	{
		if (cnt < ans)
			ans = cnt;
	}
}

void DFS(int depth, int start)
{
	if (depth == m)
	{
		/*	for (int i = 0; i < m; i++)
		{
			cout << vec[i] << " ";
		}
		cout << endl;*/
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
			visit[i] = false;
			vec.pop_back();
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
	cout.tie(0);
	ios::sync_with_stdio(0);
	Input();
	Solve();
	if (ans == 987654321)
		ans = -1;
	cout << ans;
}
