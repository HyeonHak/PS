#include <string>
#include <vector>
#include <iostream>
#include <limits.h>

using namespace std;

int ans = INT_MAX;
int digit_cnt(int number)
{
    if (number == 1)
        return (0);
    int ret = 0;
    while (number >= 10)
    {
        ret++;
        number /= 10;
    }
    if (number != 0)
        ret++;
    return (ret);
}

void solve(string s, int str_len)
{
    string str;
    string next;
    int cnt = 0;
    int repeat = 1;

    str = s.substr(0, str_len);
    for (int i = str_len; i < s.size(); i = i + str_len)
    {
        next = s.substr(i, str_len);

        if (str == next)
            repeat++;
        else
        {
            cnt += digit_cnt(repeat) + str.size();
            repeat = 1;
            str = next;
        }
    }
    cnt += digit_cnt(repeat) + str.size();
    if (str_len == 1)
    {
        cout << digit_cnt(repeat) << " " << str << endl;
        cout << cnt;
    }
    if (ans > cnt)
        ans = cnt;
}

int solution(string s)
{
    int answer = 0;
    for (int i = 1; i <= s.size(); i++)
        solve(s, i);
    return ans;
}