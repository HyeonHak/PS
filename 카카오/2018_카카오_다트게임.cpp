//11 : 37
#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

typedef struct Info
{
    int score;
    char location;
    char option = ' ';
} info;

vector<info> vec;

int num_width(int number)
{
    if (number == 10)
        return (2);
    else
        return (1);
}

int is_option(char ch)
{
    return (ch == '*' || ch == '#');
}

void score_cal(vector<info> &vec, int idx)
{
    if (vec[idx].location == 'D')
        vec[idx].score = pow(vec[idx].score, 2);
    else if (vec[idx].location == 'T')
        vec[idx].score = pow(vec[idx].score, 3);
}

void option_cal(vector<info> &vec, int idx)
{
    if (vec[idx].option == '*')
    {
        if (idx == 0)
            vec[idx].score *= 2;
        else
        {
            vec[idx].score *= 2;
            vec[idx - 1].score *= 2;
        }
    }
    else if (vec[idx].option == '#')
        vec[idx].score = vec[idx].score * -1;
}

int solution(string dartResult)
{
    int answer = 0;
    int i = 0;
    for (; i < dartResult.size();)
    {
        info input;

        int number = stoi(dartResult);
        input.score = number;
        i += num_width(number);
        input.location = dartResult[i++];
        if (is_option(dartResult[i]))
            input.option = dartResult[i++];
        vec.push_back(input);
        dartResult = dartResult.substr(i);
        if (dartResult.size() == 0)
            break;
        i = 0;
    }
    for (int i = 0; i < vec.size(); i++)
    {
        score_cal(vec, i);
        option_cal(vec, i);
    }
    for (int i = 0; i < vec.size(); i++)
        answer += vec[i].score;
    return answer;
}