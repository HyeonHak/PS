#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

typedef struct info
{
    string name;
    int number;
} info;
vector<info> vec, origin;

bool compare(info &a, info &b)
{
    return a.name < b.name;
}

int is_digit(string str)
{
    if (str[0] >= '0' && str[0] <= '9')
        return (1);
    return (0);
}

void binary_search(string str, int SIZE)
{
    int min = 0;
    int max = SIZE;

    while (min <= max)
    {
        int mid = (min + max) / 2;
        if (vec[mid].name == str)
        {
            cout << vec[mid].number << "\n";
            return;
        }
        else if (vec[mid].name < str)
            min = mid + 1;
        else
            max = mid - 1;
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    string input;
    info tmp;

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        cin >> input;
        tmp.name = input;
        tmp.number = i;
        vec.push_back(tmp);
    }
    origin = vec;
    sort(vec.begin(), vec.end(), compare);
    for (int i = 0; i < m; i++)
    {
        cin >> input;
        if (is_digit(input))
        {
            int number = stoi(input);
            cout << origin[number - 1].name << "\n";
        }
        else
            binary_search(input, n);
    }

    return (0);
}