#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;

    cin >> tc;
    for (int i = 1; i <= tc; i++)
    {
        int k;
        cin >> k;
        vector<int> vec;
        for (int i = 0; i < k; i++)
        {
            int input;
            cin >> input;
            if (input == 0)
                vec.pop_back();
            else
                vec.push_back(input);
        }
        int ans = 0;
        for (int i = 0; i < vec.size(); i++)
            ans += vec[i];
        cout << "#" << i << " " << ans << "\n";
    }
}