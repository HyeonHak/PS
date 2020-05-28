#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n;
long long ans;
vector<string> vec;
int value[11];
bool visit[11];

void Input()
{
	string str;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		vec.push_back(str);
	}
}

void calc()
{
	long long tmp = 0;

	for (int i = 0; i < n; i++)
	{
		long long val = 0;
		if (value[vec[i][0] - 'A'] == 0)
			return;
		for (int j = 0; j < vec[i].size(); j++)
			val = val * 10 + value[vec[i][j] - 'A'];
		tmp += val;
	}
	if (tmp > ans)
		ans = tmp;
	return;
}

void DFS(int depth)
{
	if (depth == 10)
	{
		calc();
		return;
	}

	for (int i = 0; i < 10; i++)
	{
		if (!visit[i])
		{
			visit[i] = true;
			value[depth] = i;
			DFS(depth + 1);
			visit[i] = false;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	Input();
	DFS(0);
	cout << ans;
}
