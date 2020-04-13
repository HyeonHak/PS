#include <iostream>
#include <cstring>
using namespace std;

int n;
int p;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;

    cin >> tc;
    for (int i = 1; i <= tc; i++)
    {
        int ans = 0;
        int arr[5001];
        memset(arr, 0, sizeof(arr));

        cin >> n;

        for (int j = 0; j < n; j++)
        {
            int a, b;
            cin >> a >> b;
            for (int k = a; k <= b; k++)
                arr[k]++;
        }
        cin >> p;
        cout << "#" << i << " ";
        for (int j = 0; j < p; j++)
        {
            int input;
            cin >> input;
            cout << arr[input] << " ";
        }
        cout<<"\n";
    }
}