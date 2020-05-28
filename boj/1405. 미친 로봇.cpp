#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n;
int arr[4];
bool visit[50][50];
vector<char> vec;
double p, m;
void Input()
{
	cin >> n;
	for (int i = 0; i < 4; i++)
		cin >> arr[i];
}

bool check()
{
	memset(visit, 0, sizeof(visit));
	int sy = 25;
	int sx = 25;
	visit[sy][sx] = true;
	int dy, dx;

	for (int i = 0; i < n; i++)
	{
		if (vec[i] == 'E')
		{
			dy = sy;
			dx = sx + 1;
		}
		else if (vec[i] == 'W')
		{
			dy = sy;
			dx = sx - 1;
		}
		else if (vec[i] == 'S')
		{
			dy = sy + 1;
			dx = sx;
		}
		else if (vec[i] == 'N')
		{
			dy = sy - 1;
			dx = sx;
		}

		if (!visit[dy][dx])
		{
			visit[dy][dx] = true;
			sy = dy;
			sx = dx;
		}
		else
			return false;
	}
	return true;
}

void DFS(int depth)
{
	if (depth == n)
	{
		if (!check())
			m++;
		else
			p++;
		return;
	}

	for (int i = 0; i < arr[0]; i++)
	{
		vec.push_back('E');
		DFS(depth + 1);
		vec.pop_back();
	}
	for (int i = 0; i < arr[1]; i++)
	{
		vec.push_back('W');
		DFS(depth + 1);
		vec.pop_back();
	}
	for (int i = 0; i < arr[2]; i++)
	{
		vec.push_back('S');
		DFS(depth + 1);
		vec.pop_back();
	}
	for (int i = 0; i < arr[3]; i++)
	{
		vec.push_back('N');
		DFS(depth + 1);
		vec.pop_back();
	}
}

void Solve()
{
	DFS(0);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	Input();
	Solve();
	cout << p / (m + p) << endl;
	cout << m << " " << p << endl;
}
