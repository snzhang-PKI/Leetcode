#include <iostream>

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


int main(int argc, char const *argv[])
{
    
    Trie obj = Trie();
    for (int i = 0; i < 60; i++)
    {
        obj.insert("aaa");
    }
    cout<<obj.search("aaa")<<endl;
    cout<<obj.startsWith("a")<<endl;
    return 0;
}
/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */