#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    for (int tc = 0; tc < T; tc++)
    {
        int a, b;
        cin >> a >> b;
        int check[11];
        memset(check, 0, sizeof(check));
        check[a % 10] = 1;
        vector<int> vec;
        vec.push_back(a % 10);
        int cnt = 1;
        int start = a;

        while (1)
        {
            a = a * start;
            if (check[a % 10] == 0)
            {
                check[a % 10] = 1;
                vec.push_back(a % 10);
                cnt++;
            }
            else
                break;
        }

        int value = b % cnt;
        if (value == 0)
            cout << vec[vec.size() - 1] << "\n";
        else
            cout << vec[value - 1] << "\n";
    }
}