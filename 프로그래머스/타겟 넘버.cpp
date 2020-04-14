#include <string>
#include <iostream>
#include <vector>

using namespace std;

int arr[21];
int depth;
int ans;
void DFS(int cur, vector<int> &numbers, int target)
{
    if (depth == cur)
    {
        int cnt = 0;
        if (arr[0] == 1)
            cnt = numbers[0];
        else
            cnt = numbers[0] * -1;
        for (int i = 1; i < numbers.size(); i++)
        {
            if (arr[i] == 1)
                cnt += numbers[i];
            else
                cnt = cnt + numbers[i] * -1;
        }
        if (cnt == target)
            ans++;
        return;
    }
    arr[cur] = 1;
    DFS(cur + 1, numbers, target);
    arr[cur] = 2;
    DFS(cur + 1, numbers, target);
}

int solution(vector<int> numbers, int target)
{
    int answer = 0;
    depth = numbers.size();
    DFS(0, numbers, target);
    answer = ans;
    return answer;
}
