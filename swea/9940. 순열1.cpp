#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;
int N;
int visit[100001];
string ans;
vector<int> vec;

void Input()
{
	int input;
	ans = "Yes";

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> input;
		visit[input]++;
		if (visit[input] >= 2)
			ans = "No";
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
		cout << "#" << t << " " << ans << "\n";
		memset(visit, 0, sizeof(visit));
	}
}
