#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int map[22][22];
int div_map[22][22];
int arr[5];
int ans = 987654321;
int dir[4][2] = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
typedef struct info
{
	int y;
	int x;
} info;
info input;
vector<info> vec;

bool inside(int y, int x)
{
	return y >= 0 && y < n && x >= 0 && x < n;
}

void Input()
{
	cin >> n;
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
			cin >> map[y][x];
	}
}

void calc()
{
	int tmp[5];
	for (int i = 0; i < 5; i++)
		tmp[i] = 0;

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			tmp[div_map[y][x] - 1] += map[y][x];
		}
	}
	sort(tmp, tmp + 5);

	if (ans > tmp[4] - tmp[0])
		ans = tmp[4] - tmp[0];
}

void print()
{
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			div_map[y][x] = 5;
		}
	}
	int cnt = vec[0].x;
	int minus = 0;

	for (int y = 0; y < vec[3].y; y++)
	{
		if (y >= vec[0].y)
			minus++;
		for (int x = 0; x <= vec[0].x - minus; x++)
		{
			div_map[y][x] = 1;
		}
	}

	minus = 0;

	for (int y = 0; y <= vec[1].y; y++)
	{
		if (y > vec[0].y)
			minus++;
		for (int x = vec[0].x + 1 + minus; x < n; x++)
		{
			div_map[y][x] = 2;
		}
	}

	minus = -1;
	cnt = vec[3].x;

	for (int y = vec[3].y; y < n; y++)
	{
		if (y <= vec[2].y)
			minus++;
		for (int x = 0; x < vec[3].x + minus; x++)
		{
			div_map[y][x] = 3;
		}
	}

	minus = 0;

	for (int y = vec[1].y + 1; y < n; y++)
	{
		if (y <= vec[2].y)
			minus++;
		for (int x = vec[1].x - minus; x < n; x++)
		{
			div_map[y][x] = 4;
		}
	}
}

void DFS(int sy, int sx, int cy, int cx, int cnt)
{
	if (cnt == 4)
	{
		if (sy == cy && sx == cx)
		{
			print();
			cout << endl;
			for (int y = 0; y < n; y++)
			{
				for (int x = 0; x < n; x++)
				{
					cout << div_map[y][x] << " ";
				}
				cout << endl;
			}
			calc();
		}
		return;
	}

	int dy = cy;
	int dx = cx;

	while (1)
	{
		dy += dir[cnt][0];
		dx += dir[cnt][1];
		if (!inside(dy, dx))
			break;
		else
		{
			div_map[dy][dx] = 5;
			input.y = dy;
			input.x = dx;
			vec.push_back(input);
			DFS(sy, sx, dy, dx, cnt + 1);
			div_map[dy][dx] = 0;
			vec.pop_back();
		}
	}
}

void Solve()
{
	for (int y = 0; y < n - 2; y++)
	{
		for (int x = 1; x < n - 1; x++)
		{
			div_map[y][x] = 5;
			input.y = y;
			input.x = x;
			vec.push_back(input);
			DFS(y, x, y, x, 0);
			div_map[y][x] = 0;
			vec.pop_back();
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	Input();
	Solve();
	cout << ans;
}
