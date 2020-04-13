#include <string>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

vector<int> parent;

int Find(int num)
{
    if (parent[num] == num)
        return num;
    parent[num] = Find(parent[num]);
    return parent[num];
}

void Union(int num1, int num2)
{
    num1 = Find(num1);
    num2 = Find(num2);
    if (num1 != num2)
        parent[num1] = num2;
}

vector<long long> solution(long long k, vector<long long> room_number)
{
    vector<long long> answer;
    int room[k + 1];
    memset(room, 0, sizeof(room));

    for (long long i = 0; i < room_number.size(); i++)
    {
        parent.push_back(room_number[i]);
        if (room[room_number[i]] == 0)
        {
            room[room_number[i]] = 1;
            answer.push_back(room_number[i]);
            if (k != room_number[i])
                Union(room_number[i], room_number[i] + 1);
        }
        else
        {
            int p = Find(room_number[i]);
            room[p] = 1;
            answer.push_back(p);
            if (k != p)
                Union(p, p + 1);
        }
    }
    return answer;
}