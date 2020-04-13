#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int ans = 0;
int N, M, K, A, B;
typedef struct Info
{
    int client_num = -1;
    int time = 0;
} info;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    int input;
    info input_info;
    cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        cin >> N >> M >> K >> A >> B;

        int reception_time[N + 1];
        int repair_time[M + 1];
        int client[K + 1];
        int arr[K + 1];

        memset(arr, 0, sizeof(arr));
        info reception_desk[N + 1];
        info repair_desk[M + 1];

        queue<info> reception_wating, repair_wating;

        for (int i = 1; i <= N; i++)
        {
            cin >> input;
            reception_time[i] = input;
        }
        for (int i = 1; i <= M; i++)
        {
            cin >> input;
            repair_time[i] = input;
        }
        for (int i = 1; i <= K; i++)
        {
            cin >> input;
            client[i] = input;
        }

        int T = 0;
        int finish = 0;

        while (finish != K)
        {
            for (int i = 1; i <= K; i++)
            {
                if (T >= client[i])
                {
                    input_info.client_num = i;
                    input_info.time = client[i];
                    reception_wating.push(input_info);
                    client[i] = 1000000;
                }
            }
            for (int i = 1; i <= N; i++)
            {
                if (reception_desk[i].client_num == -1)
                {
                    if (!reception_wating.empty())
                    {
                        info cur = reception_wating.front();
                        reception_wating.pop();
                        reception_desk[i].client_num = cur.client_num;
                        reception_desk[i].time = reception_time[i];
                        if (A == i)
                            arr[cur.client_num]++;
                    }
                }
                else
                {
                    reception_desk[i].time -= 1;

                    if (reception_desk[i].time == 0)
                    {
                        input_info.client_num = reception_desk[i].client_num;
                        input_info.time = i;
                        if (!reception_wating.empty())
                        {
                            info cur = reception_wating.front();
                            reception_wating.pop();
                            reception_desk[i].client_num = cur.client_num;
                            reception_desk[i].time = reception_time[i];
                        }
                        else
                            reception_desk[i].client_num = -1;
                        repair_wating.push(input_info);
                    }
                }
            }

            for (int i = 1; i <= M; i++)
            {
                if (repair_desk[i].client_num == -1)
                {
                    if (!repair_wating.empty())
                    {
                        info cur = repair_wating.front();
                        repair_wating.pop();
                        repair_desk[i].client_num = cur.client_num;
                        repair_desk[i].time = repair_time[i];
                        if (B == i)
                            arr[cur.client_num]++;
                    }
                }
                else
                {
                    repair_desk[i].time -= 1;
                    if (repair_desk[i].time == 0)
                    {
                        if (!repair_wating.empty())
                        {
                            info cur = repair_wating.front();
                            repair_wating.pop();
                            repair_desk[i].client_num = cur.client_num;
                            repair_desk[i].time = repair_time[i];
                            if (B == i)
                                arr[cur.client_num]++;
                        }
                        else
                            repair_desk[i].client_num = -1;
                        finish++;
                    }
                }
            }

            T++;
        }

        for (int i = 1; i <= K; i++)
        {
            cout << arr[i] << " ";
            if (arr[i] == 2)
                ans += i;
        }
        if (ans == 0)
            ans = -1;
        cout << "#" << t << " " << ans << "\n";
        ans = 0;
    }
}