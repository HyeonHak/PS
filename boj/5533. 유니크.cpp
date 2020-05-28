#include <iostream>
#include <vector>
using namespace std;
int n;
vector<int> vec[201];
int ans[201];

void Input()
{
	int value;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> value;
			vec[i].push_back(value);
		}
	}
}

void Solve()
{
	for (int i = 0; i < 3; i++)
	{
		int num[101];
		for (int j = 1; j <= 100; j++)
			num[j] = 0;
		for (int j = 0; j < n; j++)
			num[vec[j][i]]++;
		for (int j = 0; j < n; j++)
		{
			if (num[vec[j][i]] == 1)
				ans[j] += vec[j][i];
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	Input();
	Solve();

	for (int i = 0; i < n; i++)
		cout << ans[i] << "\n";
}
