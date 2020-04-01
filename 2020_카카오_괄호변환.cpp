#include <string>
#include <vector>
#include <iostream>

using namespace std;

int is_right(string s)
{
    vector<char> vec;
    int top = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (vec.empty())
        {
            if (s[i] == ')')
                return (0);
            else if (s[i] == '(')
            {
                vec.push_back(s[i]);
                top++;
            }
        }
        else
        {
            if (vec[top] == ')')
                return (0);
            else if (vec[top] == '(')
            {
                if (s[i] == ')')
                {
                    top--;
                    vec.pop_back();
                }
                else if (s[i] == '(')
                {
                    top++;
                    vec.push_back(s[i]);
                }
            }
        }
    }
    if (vec.empty())
        return (0);
    return (1);
}

string div(string p)
{
    string ret;
    int open = 0;
    int close = 0;

    for (int i = 0; i < p.size(); i++)
    {
        if (p[i] == ')')
            close++;
        else
            open++;
        if (open == close)
        {
            ret = p.substr(0, i + 1);
            break;
        }
    }
    return (ret);
}

string recursive(string p)
{
    string u;
    string v = "";

    if (p.empty())
        return ("");
    u = div(p);
    v = p.substr(u.size());
    if (is_right(u))
    {
        u += recursive(v);
        return (u);
    }
    else
    {
        string tmp = "(";
        tmp += recursive(v);
        tmp += ")";
        for (int i = 1; i < u.size() - 1; i++)
        {
            if (u[i] == ')')
                tmp += '(';
            else
                tmp += ')';
        }
        return (tmp);
    }
}

string solution(string p)
{
    string answer = "";
    answer = recursive(p);
    return answer;
}