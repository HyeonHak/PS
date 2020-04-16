#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n;
int ans;
string input;
vector<string> vec;
int cnt;
bool check[10];
int arr[27];
int alpha[27];
int visit[27];
vector<char> List;

void Insert(string str)
{
    for (int i = 0; i < str.size(); i++)
    {
        if (visit[str[i] - 'A'] == 0)
            visit[str[i] - 'A'] = ++cnt;
    }
}

void calc()
{
    int ret = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        int tmp = 0;
        for (int j = 0; j < vec[i].size(); j++)
        {
            tmp = tmp * 10 + arr[visit[vec[i][j] - 'A']];
        }
        ret += tmp;
    }
    if (ans < ret)
        ans = ret;
}

void DFS(int cur)
{
    if (cur == cnt + 1)
    {
        calc();
        return;
    }
    for (int i = 0; i < 10; i++)
    {
        if (check[i] == false)
        {
            check[i] = true;
            arr[cur] = i;
            DFS(cur + 1);
            check[i] = false;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        vec.push_back(input);
        Insert(input);
    }

    DFS(1);
    cout << ans;
}