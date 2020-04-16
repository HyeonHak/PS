#include <iostream>
#include <vector>
using namespace std;

int arr[11];
int target[4];

typedef struct info
{
    int blue;
    int red;
} info;
vector<info> vec[51][2];

void map_setting()
{
    info data;
    for (int i = 0; i <= 40; i = i + 2)
    {
        if (i == 10 || i == 20 || i == 30)
        {
            if (i == 10)
                data.blue = 13;
            else if (i == 20)
                data.blue = 22;
            else if (i == 30)
                data.blue = 28;
        }
        data.red = i + 2;
        vec[i][0].push_back(data);
    }

    for (int i = 13; i <= 19;)
    {
        if (i == 19)
        {
            data.red = 25;
            vec[19][0].push_back(data);
        }
        else
        {
            data.red = i + 3;
            vec[i][0].push_back(data);
        }
        i = i + 3;
    }
    for (int i = 22; i <= 24;)
    {
        if (i == 24)
        {
            data.red = 25;
            vec[i][0].push_back(data);
        }
        else
        {
            data.red = i + 2;
            vec[i][0].push_back(data);
        }
        i = i + 2;
    }

    for (int i = 28; i <= 26;)
    {
        if (i == 26)
        {
            data.red = 25;
            vec[i][0].push_back(data);
        }
        else
        {
            data.red = i - 1;
            vec[i][0].push_back(data);
        }
        i = i - 1;
    }
    for (int i = 25; i <= 35;)
    {
        data.red = i + 5;
        vec[i][0].push_back(data);
        i = i + 5;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < 10; i++)
    {
        cin >> arr[i];
    }
    map_setting();
    
}