#include <string>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

struct FRONT_TRIE
{
    int cnt[26][10001];
    FRONT_TRIE *node[26];
    FRONT_TRIE()
    {
        memset(cnt, 0, sizeof(cnt));
        memset(node, false, sizeof(node));
    }
    void insert(string &str)
    {
        if (str.empty())
            return;
        int cur = str[0] - 'a';
        if (node[cur] == NULL)
        {
            node[cur] = new FRONT_TRIE();
            cnt[cur][str.size() - 1] = 1;
        }
        else
            cnt[cur][str.size() - 1]++;
        //cout << str << " " << str.size() - 1 << " " << cnt[cur][str.size() - 1] << endl;
        string next = str.substr(1);
        node[cur]->insert(next);
    }

    int find(string &str)
    {
        int cur = str[0] - 'a';
        if (node[cur] == NULL)
            return 0;
        if (str[1] == '?')
            return cnt[cur][str.size() - 1];
        string next = str.substr(1);
        return node[cur]->find(next);
    }
};

struct BACK_TRIE
{
    int cnt[26][10001];
    BACK_TRIE *node[26];
    BACK_TRIE()
    {
        memset(cnt, 0, sizeof(cnt));
        memset(node, false, sizeof(node));
    }
    void insert(string &str)
    {
        if (str.empty())
            return;
        int cur = str[0] - 'a';
        if (node[cur] == NULL)
        {
            node[cur] = new BACK_TRIE();
            cnt[cur][str.size() - 1] = 1;
        }
        else
            cnt[cur][str.size() - 1]++;
        //cout << str << " " << str.size() - 1 << " " << cnt[str.size() - 1] << endl;
        string next = str.substr(1);
        node[cur]->insert(next);
    }

    int find(string &str)
    {
        int cur = str[0] - 'a';
        if (node[cur] == NULL)
            return 0;
        if (str[1] == '?')
            return cnt[cur][str.size() - 1];
        string next = str.substr(1);
        return node[cur]->find(next);
    }
};

vector<int> solution(vector<string> words, vector<string> queries)
{
    vector<int> answer;
    FRONT_TRIE *FT = new FRONT_TRIE();
    BACK_TRIE *BT = new BACK_TRIE();

    for (int i = 0; i < words.size(); i++)
    {
        string tmp;

        FT->insert(words[i]);
        for (int j = words[i].size() - 1; j >= 0; j--)
            tmp += words[i][j];
        BT->insert(tmp);
        cout << endl;
    }

    for (int i = 0; i < queries.size(); i++)
    {
        if (queries[i][0] == '?')
        {
            string tmp;
            for (int j = queries.size() - 1; j >= 0; j--)
                tmp += queries[i][j];
            answer.push_back(BT->find(tmp));
        }
        else
            //if (queries[i][0] != '?')
            answer.push_back(FT->find(queries[i]));
    }

    return answer;
}