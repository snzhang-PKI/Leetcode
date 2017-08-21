//用prefixtree检查某个前缀是否出现过 若从未出现过 则直接终止 避免不必要的计算
//先存cut 然后再把cut转换成string的结果
//减少dp里面不必要的子问题的计算 提高子问题的计算效率

#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <list>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Trie 
{
public:
    /** Initialize your data structure here. */
    Trie() 
    {
        this->isLeaf = false;

        for (int i = 0; i < 26; i++)
        {
            this->child[i] = nullptr;
        }
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) 
    {
        Trie* t = this;

        for (auto c : word)
        {
            int i = c - 'a';
            
            if (t->child[i] == nullptr)
            {
                t->child[i] = new Trie();
            }
            
            t = t->child[i];
        }

        t->isLeaf = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) 
    {
        Trie* t = this;
        for (auto c : word)
        {
            int i = c - 'a';
        
            if (t->child[i] == nullptr)
            {
                return false;
            }
            
            t = t->child[i];
        }
        
        if (t->isLeaf)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) 
    {
        Trie* t = this;
        for (auto c : prefix)
        {
            int i = c - 'a';
            if (t->child[i] == nullptr)
            {
                return false;
            }
            t = t->child[i];
        }
        return true;
    }

private:

    bool isLeaf;
    Trie* child[26];
};

class Solution 
{
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) 
    {
        vector<string> res;
        Trie* root = new Trie();
        int l = s.size();
        int maxWordLength = 0;
        for (auto w : wordDict)
        {
            if (w.size() > maxWordLength)
            {
                maxWordLength = w.size();
            }
            root->insert(w);
        }  

        vector<vector<int>> dp(l,vector<int>());

        for (int i = 0; i < l; i++)
        {
            // cout<<i<<endl;
            bool hasPrefix = false;

            for (int j = max(i - maxWordLength + 1, 0); j <= i; j++)
            {
                string w = s.substr(j,i-j+1);

                if (root->search(w) && (j == 0 || !dp[j-1].empty()))
                {
                    dp[i].push_back(j-1);
                }
                if (root->startsWith(w))
                {
                    hasPrefix = true;
                }
            }

            if (hasPrefix == false)
            {
                return res;
            }
        }
        
        for (auto el : dp)
        {
            if (el.empty())
            {
                continue;
            }
            for (auto e : el)
            {
                cout<<e<<" "<<s[e]<<" ";
            }
            cout<<endl;
        }
        vector<list<int>> cut;
        stack<list<int>> dfs;

        for (auto lastCut : dp[l-1])
        {
            dfs.push({lastCut});
        }

        while (!dfs.empty())
        {
            auto frontier = dfs.top();
            dfs.pop();
            int i = frontier.front();
            if (i == -1)
            {
                cut.push_back(frontier);
                continue;
            }
            for (auto head : dp[i])
            {
                list<int> t = frontier;
                t.push_front(head);
                dfs.push(t);
            }
        }

        for (auto c : cut)
        {
            for (auto i : c)
            {
                cout<<i<<" ";
            }
            cout<<endl;
        }

        for (auto c : cut)
        {
            string r = s;
            for (auto it = c.rbegin(); it != c.rend(); it++)
            {
                if (*it == -1)
                {
                    break;
                }
                r.insert(*it + 1," ");
            }
            res.push_back(r);
        }

        for (auto r : res)
        {
            cout<<r<<endl;
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution mySol;
    vector <string> d = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
    string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    mySol.wordBreak(s,d);
    return 0;
}