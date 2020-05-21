//11: 37
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef struct info
{
    int start_hour;
    int start_minute;
    int end_hour;
    int end_minute;
    string name;
    vector<string> sheet_music;
    int time;

} info;
vector<info> ans;

bool compare(info &a, info &b)
{
    if (a.time == b.time)
        return 0;
    return a.time > b.time;
}

string solution(string m, vector<string> musicinfos)
{
    string answer = "";
    for (int i = 0; i < musicinfos.size(); i++)
    {
        vector<string> sheet_music;
        string name;
        int s_h, e_h, s_m, e_m;

        s_h = stoi(musicinfos[i].substr(0, 2));
        musicinfos[i] = musicinfos[i].substr(3);
        s_m = stoi(musicinfos[i].substr(0, 2));
        musicinfos[i] = musicinfos[i].substr(3);

        e_h = stoi(musicinfos[i].substr(0, 2));
        musicinfos[i] = musicinfos[i].substr(3);
        e_m = stoi(musicinfos[i].substr(0, 2));
        musicinfos[i] = musicinfos[i].substr(3);

        int k = 0;
        for (; k < musicinfos[i].size(); k++)
        {
            if (musicinfos[i][k] == ',')
                break;
            name += musicinfos[i][k];
        }
        musicinfos[i] = musicinfos[i].substr(k + 1);

        for (int j = 0; j < musicinfos[i].size(); j++)
        {
            string tmp_str;
            if (musicinfos[i][j] == '#')
            {
                string tmp_str = sheet_music.back();
                tmp_str.push_back('#');
                sheet_music[sheet_music.size() - 1] = tmp_str;
            }
            else
            {
                tmp_str.push_back(musicinfos[i][j]);
                sheet_music.push_back(tmp_str);
            }
        }

        vector<string> str;
        int time = (e_h - s_h) * 60 + e_m - s_m;
        for (int j = 0; j < time; j++)
        {
            string tmp = sheet_music[j % sheet_music.size()];
            str.push_back(tmp);
        }

        int cnt = 0;

        int m_size = m.size();
        for (int k = 0; k < m.size(); k++)
            if (m[k] == '#')
                m_size--;
        while (1)
        {
            if (str.size() - cnt < m_size)
                break;
            string tmp;
            for (int i = cnt; i < cnt + m_size; i++)
                tmp += str[i];
            if (tmp == m)
            {
                info input = {s_h, s_m, e_h, e_m, name, sheet_music, time};
                ans.push_back(input);
                break;
            }
            else
                cnt++;
        }
    }
    if (ans.empty() == true)
        answer = "(None)";
    else
    {
        sort(ans.begin(), ans.end(), compare);
        answer = ans[0].name;
    }
    return answer;
}
