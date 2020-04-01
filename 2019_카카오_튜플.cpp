#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
vector<vector<int>> vec;
int check[100001];

bool compare(vector<int> &a, vector<int> &b)
{
    return a.size() < b.size();
}

int digit_cnt(int number)
{
    int ret = 0;

    if (number < 10)
        return (1);
    while (number)
    {
        number /= 10;
        ret++;
    }
    return (ret);
}

int is_digit(char ch)
{
    if (ch >= '0' && ch <= '9')
        return (1);
    return (0);
}

void div(string s)
{
    int end_cnt = 0;
    int time_cnt = 0;

    for (int i = 1; i < s.size() - 1; i++)
    {
        if (s[i] == '{')
        {
            vector<int> tmp_vec;
            string tmp = s.substr(i + 1);
            while (1)
            {
                int number = stoi(tmp);
                tmp_vec.push_back(number);
                tmp = tmp.substr(digit_cnt(number));
                if (tmp[0] == '}')
                    break;
                else if (tmp[0] == ',')
                    tmp = tmp.substr(1);
            }
            vec.push_back(tmp_vec);
        }
    }

    sort(vec.begin(), vec.end(), compare);
}

vector<int> solution(string s)
{
    vector<int> answer;
    div(s);
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[i].size(); j++)
        {
            if (check[vec[i][j]] == 0)
            {
                check[vec[i][j]] = 1;
                answer.push_back(vec[i][j]);
            }
        }
    }
    return answer;
}

int main(void)
{
    solution("{{2},{2,1},{2,1,3},{2,1,3,4}}");
}