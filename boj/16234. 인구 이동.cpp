#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int N, L, R;
int map[53][53];
int check[53][53];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int ans;

bool inside(int y, int x)
{
	return y >= 0 && y < N && x >= 0 && x < N;
}

void Input()
{
	int input;

	cin >> N >> L >> R;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
		}
	}
}

void DFS(int y, int x, int cnt)
{
	for (int i = 0; i < 4; i++)
	{
		int dy = y + dir[i][0];
		int dx = x + dir[i][1];
		//cout << dy << " " << dx << endl;
		if (!inside(dy, dx))
			continue;
		if (check[dy][dx] != 0)
			continue;
		int value = abs(map[y][x] - map[dy][dx]);
		if (value >= L && value <= R)
		{
			check[dy][dx] = cnt;
			DFS(dy, dx, cnt);
		}
	}
}

void calc()
{
	int ingu_cnt[2501];
	int ingu_num[2501];
	memset(ingu_cnt, 0, sizeof(ingu_cnt));
	memset(ingu_num, 0, sizeof(ingu_num));

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			ingu_cnt[check[y][x]]++;
			ingu_num[check[y][x]] += map[y][x];
		}
	}

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			if (ingu_cnt[check[y][x]] != 1)
				map[y][x] = ingu_num[check[y][x]] / ingu_cnt[check[y][x]];
		}
	}
}

void Solve()
{
	while (1)
	{
		int cnt = 1;
		int repeat = 0;
		int flag = 0;
		memset(check, 0, sizeof(check));

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (check[i][j] == 0)
				{
					check[i][j] = cnt;
					DFS(i, j, cnt);
					cnt++;
					repeat++;
				}
			}
		}
		if (repeat == N * N)
			return;
		calc();

		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < N; x++)
			{
				cout << map[y][x] << " ";
			}
			cout << endl;
		}
		cout << endl;
		ans++;
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	Input();
	Solve();
	cout << ans;
}
