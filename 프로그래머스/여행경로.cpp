#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;
vector<string> ans;
int flag;
void dfs(string cur_name, int cur, vector<bool> &check, vector<vector<string>> &tickets, vector<string> answer)
{
    if (flag == 1)
        return;
    if (cur == tickets.size())
    {
        flag = 1;
        for (int i = 0; i < answer.size(); i++)
            ans.push_back(answer[i]);
        ans.push_back(cur_name);
        return;
    }

    for (int i = 0; i < tickets.size(); i++)
    {
        if (tickets[i][0] == cur_name && check[i] == false)
        {
            answer.push_back(cur_name);
            check[i] = true;
            cout << tickets[i][1] << endl;
            dfs(tickets[i][1], cur + 1, check, tickets, answer);
            check[i] = false;
            answer.pop_back();
        }
    }
}

vector<string> solution(vector<vector<string>> tickets)
{
    vector<string> answer;
    vector<bool> check(tickets.size(), false);
    sort(tickets.begin(), tickets.end());

    dfs("ICN", 0, check, tickets, answer);

    return ans;
}