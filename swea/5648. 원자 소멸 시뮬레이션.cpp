//11:57
#include <iostream>
#include <vector>
#include <deque>
#include <cstring>
using namespace std;
int ans, n;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int cdir[4] = {1, 0, 3, 2};
typedef struct info
{
	int y;
	int x;
	int d;
	int k;
	int cnt;
	bool live;
} info;
info input;
vector<info> value;
deque<int> map[2001][2001];

bool inside(int y, int x)
{
	return y >= 0 && y <= 2000 && x >= 0 && x <= 2000;
}

void Input()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> input.y >> input.x >> input.d >> input.k;
		input.cnt = 0;
		input.y += 1000;
		input.x += 1000;
		input.live = true;
		value.push_back(input);
		map[input.y][input.x].push_back(i);
	}
}

void Solve()
{
	while (1)
	{
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			if (!value[i].live)
				continue;
			int dy = value[i].y + dir[value[i].d][0];
			int dx = value[i].x + dir[value[i].d][1];
			if (!inside(dy, dx))
			{
				value[i].live = false;
				continue;
			}
			// if (!map[dy][dx].empty())
			// {
			// 	value[i].live = false;
			// 	ans += value[i].k;
			// 	if (value[map[dy][dx].front()].live)
			// 	{
			// 		value[map[dy][dx].front()].live = false;
			// 		ans += value[map[dy][dx].front()].k;
			// 	}
			// 	continue;
			// }
			map[dy][dx].push_back(i);
			value[i].y = dy;
			value[i].x = dx;
			cnt++;
		}
		if (cnt == 0)
			break;
		for (int i = 0; i < n; i++)
		{
			cout << map[value[i].y][value[i].x].size() << endl;
			if (!value[i].live)
				continue;
			if (map[value[i].y][value[i].x].size() >= 2)
			{
				for (int j = 0; j < map[value[i].y][value[i].x].size(); j++)
				{
					value[map[value[i].y][value[i].x][j]].live = false;
					ans += value[map[value[i].y][value[i].x][j]].k;
				}
				map[value[i].y][value[i].x].clear();
			}
			else
				map[value[i].y + dir[cdir[value[i].d]][0]][value[i].x + dir[cdir[value[i].d]][1]].pop_back();
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++)
	{
		Input();
		Solve();
		cout << "#" << t << " " << ans << "\n";
		ans = 0;
		value.clear();
		for (int i = 0; i < 2001; i++)
		{
			for (int j = 0; j < 2001; j++)
			{
				if (!map[i][j].empty())
					map[i][j].clear();
			}
		}
	}
}
