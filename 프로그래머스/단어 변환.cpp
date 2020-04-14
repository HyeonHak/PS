#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> vec[53];
bool check[53][53];
int flag = 0;
int ans;

int posibility(string begin, string target, vector<string> words)
{
    for (int i = 0; i < words.size(); i++)
    {
        if (target == words[i])
            return (1);
    }
    return (0);
}

int compare(string str, string str2)
{
    int cnt = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] != str2[i])
            cnt++;
        if (cnt > 1)
            return -1;
    }
    if (cnt == 1)
        return 1;
}

void list_setting(string begin, string target, vector<string> words)
{
    for (int i = 0; i < words.size(); i++)
    {
        if (compare(begin, words[i]) == 1)
            vec[0].push_back(i + 1);
    }

    for (int i = 0; i < words.size(); i++)
    {
        for (int j = 0; j < words.size(); j++)
        {
            if (i == j)
                continue;
            if (compare(words[i], words[j]) == 1)
                vec[i + 1].push_back(j + 1);
        }
    }
}

void DFS(int cur_idx, string target, int answer, vector<string> &words)
{
    if (cur_idx != 0)
    {
        if (words[cur_idx - 1] == target)
        {
            if (ans != 0)
            {
                if (answer < ans)
                    ans = answer;
            }
            else
                ans = answer;
            return;
        }
    }
    for (int i = 0; i < vec[cur_idx].size(); i++)
    {
        if (check[cur_idx][vec[cur_idx][i]] == false)
        {
            check[cur_idx][vec[cur_idx][i]] = true;
            check[vec[cur_idx][i]][cur_idx] = true;
            DFS(vec[cur_idx][i], target, answer + 1, words);
        }
    }
}

int solution(string begin, string target, vector<string> words)
{
    int answer = 0;
    if (posibility(begin, target, words) == 0)
        return 0;

    list_setting(begin, target, words);
    DFS(0, target, answer, words);
    answer = ans;
    return answer;
}