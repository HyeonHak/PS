#include <iostream>
#include <vector>
using namespace std;
int N;
int flag = 0;
vector<int> vec, ans;
vector<int> ret;
bool visit[10001];

void DFS(int depth)
{
	if (flag == 2)
		return;
	if (depth == N)
	{
		if (flag == 0)
			flag = 1;
		else if (flag == 1)
		{
			ret = ans;
			flag = 2;
		}
		return;
	}
	for (int i = vec[depth]; i <= N; i++)
	{
		if (!visit[i])
		{
			visit[i] = true;
			ans.push_back(i);
			DFS(depth + 1);
			visit[i] = false;
			ans.pop_back();
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	int value;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> value;
		vec.push_back(value);
	}
	DFS(0);
	for (int i = 0; i < ret.size(); i++)
		cout << ret[i] << " ";
}
