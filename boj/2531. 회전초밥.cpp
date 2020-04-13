#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int ans;
int n, d, k, c;
vector<int> vec;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> d >> k >> c;

    /*
    n = 접시 수
    d = 초밥 가짓 수
    k = 연속해서 먹는 접시 수
    c = 쿠폰 번호
    */

    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        vec.push_back(input);
    }

    int sp = 0;
    bool check[d + 1];

    while (sp != vec.size())
    {
        vector<int> candidate;
        int ep = (sp + k) % vec.size();
        int point = sp;
        int tmp = 0;
        int flag = 0;
        memset(check, false, d + 1);
        while (point != ep)
        {
            if (check[vec[point]] == true)
                break;
            if (vec[point] == c)
                flag = -1;
            check[vec[point]] = true;
            tmp++;
            point = (point + 1) % vec.size();
        }
        if (tmp >= ans)
        {
            if (flag == 0)
                ans = tmp + 1;
            else
                ans = tmp;
        }
        sp++;
    }
    cout << ans;
}