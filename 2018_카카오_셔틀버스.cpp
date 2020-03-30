//13 : 38

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
using namespace std;

typedef struct info
{
    int hh;
    int mm;
} info;

typedef struct bus_state
{
    vector<info> human;
    info bus_start;
} bus_state;

vector<info> vec;
vector<bus_state> bus;
void insert_time(vector<string> &timetable)
{
    for (int i = 0; i < timetable.size(); i++)
    {
        info input;

        input.hh = stoi(timetable[i]);
        timetable[i] = timetable[i].substr(3);
        input.mm = stoi(timetable[i]);
        vec.push_back(input);
    }
}

bool compare(info a, info b)
{
    if (a.hh == b.hh)
        return a.mm < b.mm;
    return a.hh < b.hh;
}

void boarding(int n, int t, int m)
{
    int cnt = 0;
    int idx = 0;
    int hh = 9;
    int mm = 0;

    info human_tmp;

    while (cnt < n)
    {
        bus_state bus_tmp;
        bus_tmp.bus_start = {hh, mm};
        int amount = m;

        for (; idx < vec.size(); idx++)
        {
            if (hh < vec[idx].hh || (hh == vec[idx].hh) && mm < vec[idx].mm)
            {
                if (mm + t >= 60)
                {
                    hh += 1;
                    mm = mm + t - 60;
                }
                else
                    mm += t;
                break;
            }
            if (amount != 0)
            {
                human_tmp = vec[idx];
                bus_tmp.human.push_back(human_tmp);
                bus_tmp.bus_start.hh = hh;
                bus_tmp.bus_start.mm = mm;
                amount--;
            }
            else
            {
                if (mm + t >= 60)
                {
                    hh += 1;
                    mm = mm + t - 60;
                }
                else
                    mm += t;
                break;
            }
        }
        bus.push_back(bus_tmp);
        cnt++;
    }
}

string convert(info output)
{
    string ans;
    if (output.hh < 10)
    {
        ans = "0";
        ans += output.hh + '0';
    }
    else
    {
        ans = output.hh / 10 + '0';
        ans += output.hh % 10 + '0';
    }
    ans += ':';
    if (output.mm < 10)
    {
        ans += "0";
        ans += output.mm + '0';
    }
    else
    {
        ans += output.mm / 10 + '0';
        ans += output.mm % 10 + '0';
    }
    return (ans);
}

string solution(int n, int t, int m, vector<string> timetable)
{
    string answer = "";
    insert_time(timetable);
    sort(vec.begin(), vec.end(), compare);
    boarding(n, t, m);

    for (int i = bus.size() - 1; i >= 0; i--)
    {
        if (bus[i].human.size() < m)
        {
            answer = convert(bus[i].bus_start);
            //cout << bus[i].bus_start.hh << " " << bus[i].bus_start.mm << " ";
            return (answer);
        }
        else
        {
            int flag = 0;
            int tmp_hh = bus[i].human[bus[i].human.size() - 1].hh;
            int tmp_mm = bus[i].human[bus[i].human.size() - 1].mm;
            for (int j = bus[i].human.size(); j >= 0; j--)
            {
                if (tmp_hh == bus[i].human[j].hh && tmp_mm == bus[i].human[j].mm)
                {
                    flag = 1;
                    break;
                }
            }
            if (flag)
            {
                if (tmp_mm == 0)
                {
                    tmp_mm = 59;
                    tmp_hh -= 1;
                }
                info output = {tmp_hh, tmp_mm};
                cout << tmp_hh << " " << tmp_mm;
                answer = convert(output);
                return (answer);
            }
        }
    }
    cout << "wow";
    return (answer);
}