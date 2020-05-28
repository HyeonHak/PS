#include <iostream>
#include <vector>
using namespace std;
int ans;
char map[6][6];
bool visit[6][6][6];

bool inside(int y, int x)
{
	return y >= 0 && y < 5 && x >= 0 && x < 5;
}
int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
typedef struct Info
{
	int y;
	int x;
} info;
info input;
vector<info> vec;

bool check()
{
	for (int i = 0; i < vec.size(); i++)
	{
		int value = 1;
		info cur = vec[i];
		for (int j = 0; j < 4; j++)
		{
			int dy = cur.y + dir[j][0];
			int dx = cur.x + dir[j][1];
			if (!inside(dy, dx))
				continue;
			if (map[dy][dx] == '*')
				value++;
		}
		if (value == vec.size())
			return true;
	}
	return false;
}

int flag = 0;
void Solve(int cnt)
{
	if (flag)
		return;
	if (check())
	{
		flag = 1;
		ans = cnt;
		return;
	}

	for (int i = 0; i < vec.size(); i++)
	{
		info cur = vec[i];
		for (int j = 0; j < 4; j++)
		{
			int dy = cur.y + dir[j][0];
			int dx = cur.x + dir[j][1];
			if (!inside(dy, dx))
				continue;
			if (map[dy][dx] == '*')
				continue;
			if (!visit[dy][dx][i])
			{
				visit[dy][dx][i] = true;
				vec[i].y = dy;
				vec[i].x = dx;
				map[cur.y][cur.x] = '.';
				map[dy][dx] = '*';
				Solve(cnt + 1);
				visit[dy][dx][i] = false;
				map[cur.y][cur.x] = '*';
				map[dy][dx] = '.';
				vec[i].y = cur.y;
				vec[i].x = cur.x;
				if (flag)
					return;
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	for (int y = 0; y < 5; y++)
	{
		for (int x = 0; x < 5; x++)
		{
			cin >> map[y][x];
			if (map[y][x] == '*')
			{
				input.y = y;
				input.x = x;
				vec.push_back(input);
				visit[y][x][vec.size() - 1] = true;
			}
		}
	}
	Solve(0);
	cout << ans;
}
