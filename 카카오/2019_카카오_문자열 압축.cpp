#include <string>
#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int digit_num(int digit)
{
    int ret = 0;
    if (digit == 1)
        return (0);
    if (digit < 10)
        return (1);

    while (digit > 0)
    {
        ret++;
        digit /= 10;
    }
    return (ret);
}

int solution(string s)
{
    int answer = INT_MAX;
    int cnt = 1;

    while (cnt <= s.size())
    {
        int tmp_num = 1;
        int tmp_ans = 0;
        string tmp = s.substr(0, cnt);

        for (int i = cnt; i < s.size();)
        {
            // if (answer != INT_MAX && answer > tmp_ans)
            //     break;
            string str = s.substr(i, tmp.size());
            if (str == tmp)
                tmp_num++;
            else
            {
                int digit = digit_num(tmp_num);
                if (digit != 0)
                    tmp_ans += digit;
                tmp_ans += tmp.size();
                tmp_num = 1;
                tmp = str;
            }
            i += str.size();
        }

        int d = digit_num(tmp_num);
        if (d != 0)
            tmp_ans += d;
        tmp_ans += tmp.size();

        if (tmp_ans < answer)
            answer = tmp_ans;
        cnt++;
        //cout << cnt << " " << tmp_ans << endl;
    }
    return answer;
}