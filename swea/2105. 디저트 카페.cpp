#include <iostream>
#include <cstring>
using namespace std;

int ans, n;
int map[21][21];
int desert[101];
int dir[4][2] = {{-1, 1}, {1, 1}, {1, -1}, {-1, -1}};

bool inside(int y, int x)
{
	return y >= 0 && y < n && x >= 0 && x < n;
}

void Reset()
{
	ans = 0;
	memset(map, 0, sizeof(map));
	memset(desert, 0, sizeof(desert));
}

void Input()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
		}
	}
}

void DFS(int cy, int cx, int sy, int sx, int flag, int cnt)
{

	int dy = cy;
	int dx = cx;
	dy += dir[flag][0];
	dx += dir[flag][1];
	if (!inside(dy, dx))
		return;
	if (desert[map[dy][dx]])
	{
		if (sy == dy && sx == dx)
		{
			if (cnt - 1 > ans)
				ans = cnt - 1;
		}
		return;
	}
	else
	{
		desert[map[dy][dx]] = true;
		DFS(dy, dx, sy, sx, flag, cnt + 1);

		DFS(dy, dx, sy, sx, flag + 1, cnt + 1);
		desert[map[dy][dx]] = false;
	}
}

void Solve()
{
	for (int i = 1; i < n - 1; i++)
	{
		for (int j = 0; j < n - 2; j++)
		{
			desert[map[i][j]] = true;
			DFS(i, j, i, j, 0, 1);
			desert[map[i][j]] = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++)
	{
		Input();
		Solve();
		if (ans == 0)
			ans = -1;
		cout << "#" << t << " " << ans << "\n";
		Reset();
	}
}
