#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int map[300][300];
int key_cnt = 0;

void rotation(vector<vector<int>> &key)
{
    int tmp[key.size()][key.size()];
    for (int y = 0; y < key.size(); y++)
    {
        for (int x = 0; x < key.size(); x++)
        {
            //tmp[y][x] = key[key.size() - 1 + x][y];
            tmp[x][key.size() - 1 - y] = key[y][x];
        }
    }

    for (int y = 0; y < key.size(); y++)
    {
        for (int x = 0; x < key.size(); x++)
        {
            key[y][x] = tmp[y][x];
        }
    }
}

void map_set(int SIZE, vector<vector<int>> &key, vector<vector<int>> &lock)
{
    int start_val = key.size() - 1;
    int end_val = lock.size() + key.size() - 1;

    int dy = 0;
    int dx = 0;

    for (int y = 0; y < SIZE; y++)
    {
        for (int x = 0; x < SIZE; x++)
        {
            if (start_val <= y && end_val > y && start_val <= x && end_val > x)
            {
                map[y][x] = lock[dy][dx];
                if (map[y][x] == 0)
                    key_cnt++;
                if (dx + 1 == lock.size())
                {
                    dx = 0;
                    dy++;
                }
                else
                    dx++;
            }
            else
                map[y][x] = 0;
        }
    }
}

int check(vector<vector<int>> &key, int SIZE, vector<vector<int>> &lock)
{
    int start_val = key.size() - 1;
    int end_val = lock.size() + key.size() - 1;

    for (int y = 0; y < end_val; y++)
    {

        for (int x = 0; x < end_val; x++)
        {
            int cnt = 0;
            int flag = 0;
            for (int dy = 0; dy < key.size(); dy++)
            {
                for (int dx = 0; dx < key.size(); dx++)
                {
                    if (dy + y >= start_val && dy + y < end_val && dx + x >= start_val && dx + x < end_val)
                    {

                        if (key[dy][dx] == 1 && map[y + dy][x + dx] == 1)
                        {
                            flag = 1;
                            break;
                        }
                        else if (key[dy][dx] == 1 && map[y + dy][x + dx] == 0)
                            cnt++;
                    }
                }
                if (flag == 1)
                    break;
            }
            if (key_cnt == cnt)
                return (true);
        }
    }
    return (false);
}

void print_map(int SIZE)
{
    cout << endl;
    for (int y = 0; y < SIZE; y++)
    {
        for (int x = 0; x < SIZE; x++)
        {
            cout << map[y][x] << " ";
        }
        cout << endl;
    }
}
bool solution(vector<vector<int>> key, vector<vector<int>> lock)
{
    bool answer = true;
    int cnt = 0;
    int map_size = lock.size() + ((key.size() - 1) * 2);

    map_set(map_size, key, lock);
    while (cnt != 4)
    {
        if (check(key, map_size, lock))
            return (true);
        rotation(key);
        cnt++;
    }
    return (false);
}