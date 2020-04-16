#include <iostream>
#include <cstring>
using namespace std;

int M, N, x, y;
bool visit[40001];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin >> tc;
    for (int t = 0; t < tc; t++)
    {
        cin >> M >> N >> x >> y;
        int cnt = x;
        int flag = 0;
        int object = x % N;
        if (object == 0)
            object = N;
        int tmp = 0;

        while (visit[object] == false)
        {
            if (object == y)
                break;
            visit[object] = true;
            object = (object + M) % N;
            if (object == 0)
                object = N;
            tmp += M;
        }
        if (object != y)
            cout << -1 << "\n";
        else
            cout << cnt + tmp << "\n";
        memset(visit, false, sizeof(visit));
    }
}