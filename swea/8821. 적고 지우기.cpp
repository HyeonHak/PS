#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int ans;
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    for (int T = 1; T <= tc; T++)
    {
        string str;
        bool check[11];
        memset(check, false, sizeof(check));
        cin >> str;
        for (int i = 0; i < str.size(); i++)
        {
            if (check[str[i] - '0'] == 0)
                check[str[i] - '0'] = 1;
            else
                check[str[i] - '0'] = 0;
        }
        for (int i = 0; i < 10; i++)
        {
            if (check[i] == 1)
                ans++;
        }
        cout << "#" << T << " " << ans << "\n";
        ans = 0;
    }
}