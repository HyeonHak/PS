#include <iostream>
#include <vector>
using namespace std;

int n, ans;
int map[30][30];
typedef struct Info
{
	int score;
	bool live;
} info;
info input;

vector<info> vec;
int idx;

void Input()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> input.score;
		input.live = true;
		vec.push_back(input);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> map[i][j];
	}
	cin >> idx;
}

int flag = 0;
void Solve(int N, int cnt)
{
	if (flag == 1)
		return;
	if (N == 1 || vec[idx].live == false)
	{
		if (N == 1 && vec[idx].live == true)
			flag = 1;
		if (ans < cnt)
			ans = cnt;
		return;
	}
	//밤
	if (N % 2 == 0)
	{
		for (int i = 0; i < n; i++)
		{
			if (idx == i)
				continue;
			if (!vec[i].live)
				continue;
			vec[i].live = false;
			for (int j = 0; j < n; j++)
				vec[j].score += map[i][j];
			Solve(N - 1, cnt + 1);
			for (int j = 0; j < n; j++)
				vec[j].score -= map[i][j];
			vec[i].live = true;
		}
	}
	//낮
	else
	{
		int value = 0;
		for (int i = 0; i < n; i++)
		{
			if (vec[i].live)
			{
				if (value < vec[i].score)
					value = vec[i].score;
			}
		}
		for (int i = 0; i < n; i++)
		{
			if (vec[i].live)
			{
				if (value == vec[i].score)
				{
					vec[i].live = false;
					Solve(N - 1, cnt);
					vec[i].live = true;
					return;
				}
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	Input();
	Solve(n, 0);
	cout << ans;
}
