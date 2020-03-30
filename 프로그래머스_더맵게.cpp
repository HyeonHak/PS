// 15 : 41
#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

priority_queue<int, vector<int>, greater<int>> que;

int solution(vector<int> scoville, int K)
{
    int answer = 0;
    for (int i = 0; i < scoville.size(); i++)
        que.push(scoville[i]);
    while (!que.empty())
    {
        if (que.top() >= K)
            break;
        answer++;
        int number = que.top();
        que.pop();
        if (que.empty())
            break;
        int number2 = que.top();
        que.pop();
        que.push(number + (number2 * 2));
    }
    if (que.empty())
        answer = -1;
    return answer;
}