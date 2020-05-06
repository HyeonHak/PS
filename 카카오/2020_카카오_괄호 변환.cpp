#include <string>
#include <iostream>
#include <vector>

using namespace std;

int right_string(string p)
{
    vector<char> vec;
    for (int i = 0; i < p.size(); i++)
    {
        if (p[i] == ')')
        {
            if (vec.empty())
                return -1;
            else
                vec.pop_back();
        }
        else
            vec.push_back('(');
    }
    if (vec.empty())
        return 1;
    return -1;
}

int balanced_string(string p)
{
    int cnt = 0;
    for (int i = 0; i < p.size(); i++)
    {
        if (p[i] == ')')
            cnt++;
        else
            cnt--;
    }
    if (cnt == 0)
        return 1;
    return -1;
}

string div_string(string p)
{
    if (p.empty())
        return p;
    string u, v;

    for (int i = 2; i <= p.size(); i += 2)
    {
        u = p.substr(0, i);
        if (balanced_string(u) == 1)
        {
            v = p.substr(i);
            if (right_string(u) == 1)
            {
                v = div_string(v);
                u += v;
                return (u);
            }
            else
            {
                string tmp = "(";
                tmp += div_string(v);
                cout << tmp << endl;

                tmp += ")";

                for (int i = 1; i < u.size() - 1; i++)
                {
                    if (u[i] == ')')
                        tmp += "(";
                    else
                        tmp += ")";
                }

                return tmp;
            }
        }
    }
}

string solution(string p)
{
    string answer = "";
    if (right_string(p) == 1)
        answer = p;
    else
        answer = div_string(p);
    return answer;
}