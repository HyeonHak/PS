#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

vector<string> vec;

struct TRIE
{
    TRIE *node[10];
    bool finish;
    TRIE()
    {
        memset(node, false, sizeof(node));
        finish = false;
    }
    void insert(string str)
    {
        if (str.empty())
        {
            finish = true;
            return;
        }
        int cur = str[0] - '0';
        if (node[cur] == NULL)
            node[cur] = new TRIE();
        node[cur]->insert(str.substr(1));
    }
    bool Find(string str)
    {
        if (str.empty())
        {
            for (int i = 0; i < 10; i++)
            {
                if (node[i] != NULL)
                    return false;
            }
            return true;
        }
        int cur = str[0] - '0';
        if (node[cur] == NULL)
            return false;
        return node[cur]->Find(str.substr(1));
    }
};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            string str;
            cin >> str;
            vec.push_back(str);
        }
        TRIE *Root = new TRIE();
        for (int i = 0; i < vec.size(); i++)
            Root->insert(vec[i]);

        int flag = 0;
        for (int i = 0; i < vec.size(); i++)
        {
            if (Root->Find(vec[i]) == false)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
            cout << "NO\n";
        else
            cout << "YES\n";
        vec.clear();
    }
}