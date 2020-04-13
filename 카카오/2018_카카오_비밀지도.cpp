// 12 : 27
#include <string>
#include <vector>
#include <iostream>

using namespace std;

void print_map(vector<string> &map)
{
    for (int i = 0; i < map.size(); i++)
    {
        for (int j = 0; j < map[i].size(); j++)
        {
            cout << map[i][j];
        }
        cout << endl;
    }
}

vector<string> make_map(vector<string> &map1, vector<string> &map2)
{
    vector<string> tmp;
    for (int i = 0; i < map1.size(); i++)
    {
        string str;
        for (int j = 0; j < map1[i].size(); j++)
        {
            if (map1[i][j] == '#' || map2[i][j] == '#')
                str.push_back('#');
            else
                str.push_back(' ');
        }
        tmp.push_back(str);
    }
    return (tmp);
}

int to_binary(int n, int number, vector<string> &map)
{
    string tmp;
    while (number > 1)
    {
        if (number % 2 == 0)
            tmp.insert(0, " ");
        else
            tmp.insert(0, "#");
        number /= 2;
    }
    if (number == 0)
        tmp.insert(0, " ");
    else
        tmp.insert(0, "#");
    while (tmp.size() < n)
        tmp.insert(0, " ");
    map.push_back(tmp);
    return (0);
}

vector<string> arr_cal(int n, vector<int> &arr1, vector<int> &arr2)
{
    vector<string> map1;
    vector<string> map2;
    vector<string> ans;
    for (int i = 0; i < arr1.size(); i++)
    {
        to_binary(n, arr1[i], map1);
        to_binary(n, arr2[i], map2);
    }
    ans = make_map(map1, map2);
    return ans;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2)
{
    vector<string> answer;
    answer = arr_cal(n, arr1, arr2);
    return answer;
}