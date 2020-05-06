#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cstring>
using namespace std;

map<string, bool> MAP;
vector<string> vec;

int total = 0;
struct TRIE
{
    int cnt;
    TRIE *node[128];
    TRIE()
    {
        cnt = 0;
        memset(node, false, sizeof(node));
    }
    void insert(string &str)
    {
        if (str.empty())
        {
            cnt++;
            return;
        }
        string next = str.substr(1);
        int cur = str[0];
        if (node[cur] == NULL)
            node[cur] = new TRIE();
        node[cur]->insert(next);
    }
    int find(string &str)
    {

        if (str.empty())
            return cnt;
        string next = str.substr(1);
        int cur = str[0];
        return node[cur]->find(next);
    }
};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string str;
    TRIE *root = new TRIE();
    while (getline(cin, str))
    {
        vec.push_back(str);
        root->insert(str);
        total++;
    }
    sort(vec.begin(), vec.end());
    cout << fixed;
    cout.precision(4);
    for (int i = 0; i < vec.size(); i++)
    {
        if (MAP[vec[i]] == false)
        {
            MAP[vec[i]] = true;
            cout << vec[i] << " ";
            cout << (root->find(vec[i]) / (double)total) * 100 << "\n";
        }
    }
}