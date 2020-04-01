#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int ans = 0;
int check[10];
vector<string> vec;
set<vector<string>> s;

int compare(string str, string str2)
{
    if (str.size() != str2.size())
        return (0);
    for (int i = 0; i < str.size(); i++)
    {
        if (str2[i] == '*')
            continue;
        if (str[i] != str2[i])
            return (0);
    }
    return (1);
}

void recursive(int depth, vector<string> &user_id, vector<string> &banned_id, int start)
{
    if (depth == banned_id.size())
    {
        ans++;
        for (int i = 0; i < vec.size(); i++)
            cout << vec[i] << " ";
        cout << endl;
        vector<string> tmp;
        tmp = vec;
        sort(tmp.begin(), tmp.end());
        s.insert(tmp);
        return;
    }
    int flag = 0;

    for (int i = start; i < banned_id.size(); i++)
    {
        for (int j = 0; j < user_id.size(); j++)
        {
            if (check[j] == 0 && compare(user_id[j], banned_id[i]))
            {
                vec.push_back(user_id[j]);
                check[j] = 1;
                recursive(depth + 1, user_id, banned_id, i + 1);
                check[j] = 0;
                vec.pop_back();
            }
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id)
{
    int answer = 0;

    recursive(0, user_id, banned_id, 0);
    sort(vec.begin(), vec.end());

    answer = s.size();
    return answer;
}