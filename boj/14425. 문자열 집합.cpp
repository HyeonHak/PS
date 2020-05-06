#include <iostream>
#include <string>
#include <cstring>
using namespace std;

struct TRIE
{
    bool finish;
    TRIE *node[26];
    TRIE()
    {
        memset(node, false, sizeof(node));
        finish = false;
    }
    void insert(const char *str)
    {
        if (*str == '\0')
        {
            finish = true;
            return;
        }
        int cur = *str - 'a';
        if (node[cur] == NULL)
            node[cur] = new TRIE();
        node[cur]->insert(str + 1);
    }
    bool find(const char *str)
    {
        if (*str == '\0')
        {
            if (finish)
                return true;
            return false;
        }
        int cur = *str - 'a';
        if (node[cur] == NULL)
            return false;
        return node[cur]->find(str + 1);
    }
};

char str[501];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int cnt = 0;
    int N, M;
    cin >> N >> M;
    TRIE *root = new TRIE();
    for (int i = 0; i < N; i++)
    {
        cin >> str;
        root->insert(str);
    }
    for (int i = 0; i < M; i++)
    {
        cin >> str;
        if (root->find(str))
            cnt++;
    }
    cout << cnt;
}