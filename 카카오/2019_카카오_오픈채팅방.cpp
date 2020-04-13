#include <string>
#include <vector>
#include <map>
using namespace std;

void insert(string str, map<string, string> &map)
{
    int idx = str.find(' ');

    str = str.substr(idx + 1);
    idx = str.find(' ');
    string ID = str.substr(0, idx);
    string NAME = str.substr(idx + 1);
    map[ID] = NAME;
}
void Enter_record(string str, vector<string> &answer, map<string, string> &map)
{
    int idx = str.find(' ');

    str = str.substr(idx + 1);
    idx = str.find(' ');
    string ID = str.substr(0, idx);
    string NAME = str.substr(idx + 1);
    string input = map[ID];
    input += "님이 들어왔습니다.";
    answer.push_back(input);
}
void Leave_record(string str, vector<string> &answer, map<string, string> &map)
{
    int idx = str.find(' ');

    str = str.substr(idx + 1);
    idx = str.find(' ');
    string ID = str.substr(0, idx);
    string NAME = str.substr(idx + 1);
    string input = map[ID];
    input += "님이 나갔습니다.";
    answer.push_back(input);
}
vector<string> solution(vector<string> record)
{
    vector<string> answer;
    map<string, string> map;

    for (int i = 0; i < record.size(); i++)
    {
        if (record[i][0] == 'E' || record[i][0] == 'C')
            insert(record[i], map);
    }
    for (int i = 0; i < record.size(); i++)
    {
        if (record[i][0] == 'E')
            Enter_record(record[i], answer, map);
        else if (record[i][0] == 'L')
            Leave_record(record[i], answer, map);
    }
    return answer;
}