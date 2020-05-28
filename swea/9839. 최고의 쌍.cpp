#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int ans = -1;
int N;
bool visit[1001];
vector<int> vec;
vector<int> arr;
int flag = 0;

bool compare(int a, int b)
{
	return a > b;
}

void Input()
{
	int value;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> value;
		vec.push_back(value);
	}
	sort(vec.begin(), vec.end(), compare);
}

void Reset()
{
	ans = -1;
	flag = 0;
	vec.clear();
	memset(visit, false, sizeof(visit));
}

void calc()
{
	vector<int> tmp;
	long long value = vec[arr[0]] * vec[arr[1]];
	long long ori_value = value;

	while (value > 0)
	{
		int digit = value % 10;
		if (digit - 1 != value / 10 % 10)
			return;
		value /= 10;
	}

	if (ans < ori_value)
		ans = ori_value;
}

void DFS(int depth, int start)
{
	if (depth == 2)
	{
		calc();
		return;
	}

	for (int i = start; i < vec.size(); i++)
	{
		if (!visit[i])
		{
			visit[i] = true;
			arr.push_back(i);
			DFS(depth + 1, i);
			arr.pop_back();
			visit[i] = false;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++)
	{
		Input();
		DFS(0, 0);
		cout << "#" << t << " " << ans << "\n";
		Reset();
	}
}
