#include <iostream>
using namespace std;

int main(void)
{
    int n;
    cin >> n;
    int sp = 1;
    int ep = 1;
    int cnt = 0;
    int ans = 0;

    while (sp <= n)
    {
        cnt = sp;
        ep = sp + 1;
        while (cnt < n)
        {
            cnt += ep;
            ep += 1;
        }
        if (cnt == n)
            ans++;
        sp++;
        cnt = 0;
    }
    cout << ans;
}