#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int visit[102];

vector<int> ans;
vector<int> vec;

void Input()
{
	int value;
	vec.push_back(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> value;
		vec.push_back(value);
	}
}

int DFS(int num, int start)
{
	visit[num] = true;
	if (visit[vec[num]] == false)
	{
		int flag = DFS(vec[num], start);
		if (flag == 0)
		{
			visit[num] = false;
			return 0;
		}
		else
			ans.push_back(num);
	}
	else if (vec[num] == start)
	{
		ans.push_back(num);
		return 1;
	}
	else
	{
		visit[num] = false;
		return 0;
	}
	return 1;
}

void Solve()
{
	for (int i = 1; i < n; i++)
		DFS(i, i);
}

int main(void)
{
	ios::sync_with_stdio(0);
	Input();
	Solve();

	sort(ans.begin(), ans.end());
	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << "\n";
}
