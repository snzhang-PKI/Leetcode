#define Cord pair<int,int>
#define PathList list<set<pair<int,int>>>

class Trie 
{
public:
    /** Initialize your data structure here. */
    Trie() 
    {
        this->isLeaf = false;
        this->str = "";
        this->pathMap = map<Cord,PathList>();

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
                t->child[i] -> cc = c;
            }
            
            t = t->child[i];
        }

        t->isLeaf = true;
        t->str = word;
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

public:

    bool isLeaf;
    Trie* child[26];
    string str;
    map<Cord,PathList> pathMap;
    char cc;
};

class Solution 
{
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) 
    {
        vector<string> res;
        int m,n;
        m = board.size();
        if (m == 0)
        {
            return res;
        }
        else
        {
            n = board[0].size();
        }

        Trie* root = new Trie();

        for (string word : words)
        {
            root->insert(word);
        }

        stack<Trie*> trieDfsWalk;
        for (int i = 0; i < 26; i++)
        {
            Trie* currentChild = root->child[i];

            if (currentChild != nullptr)
            {
                for (int x = 0; x < m; x++)
                {
                    for (int y = 0; y < n; y++)
                    {
                        if (board[x][y] - 'a' == i)
                        {
                            currentChild->pathMap.insert(pair<Cord,PathList>(Cord(x,y),{{Cord(-1,-1)}}));
                        }
                    }
                }
                // cout<<i<<" "<<currentChild->cc<<endl;
                if (!currentChild->pathMap.empty())
                {
                    trieDfsWalk.push(currentChild);
                }
            }

        }
        int count = 0;
        while (!trieDfsWalk.empty())
        {
            // cout<<count++<<endl;
            Trie* frontier = trieDfsWalk.top();
            // if (frontier == nullptr)
                // {cout<<2<<endl;}
            // cout<<"1"<<frontier->isLeaf<<endl;
            trieDfsWalk.pop();
            // cout<<"2"<<frontier->isLeaf<<endl;
            // cout<<frontier->cc<<endl;
            // cout<<"  map size : "<<frontier->pathMap.size()<<endl;
            // for (auto p : frontier->pathMap)
            // {
            //     cout<<"      Cord can be reached from: "<<p.second.size()<<" path"<<endl;
            // }

            if (frontier->isLeaf)
            {
                res.push_back(frontier->str);
            }

            

            for (int letter = 0; letter < 26; letter++)
            {
                Trie* c = frontier->child[letter];
                if (c != nullptr)
                {
                    // cout<<"   "<<c->cc<<endl;
                    for (auto p : frontier->pathMap)
                    {
                        Cord lastCord = p.first;
                        int i = lastCord.first;
                        int j = lastCord.second;

                        PathList pathList = p.second;

                        for (set<Cord> pathToLastCord : pathList)
                        {
                            if (OnBoard(i-1,j,m,n) && board[i-1][j] == 'a' + letter && pathToLastCord.find(Cord(i-1,j)) == pathToLastCord.end())
                            {
                                set<Cord> newPathToLastCord = pathToLastCord;
                                newPathToLastCord.insert(Cord(i,j));
                                c->pathMap[Cord(i-1,j)].push_back(newPathToLastCord);
                            }
                            if (OnBoard(i+1,j,m,n) && board[i+1][j] == 'a' + letter && pathToLastCord.find(Cord(i+1,j)) == pathToLastCord.end())
                            {
                                set<Cord> newPathToLastCord = pathToLastCord;
                                newPathToLastCord.insert(Cord(i,j));
                                c->pathMap[Cord(i+1,j)].push_back(newPathToLastCord);
                            }
                            if (OnBoard(i,j-1,m,n) && board[i][j-1] == 'a' + letter && pathToLastCord.find(Cord(i,j-1)) == pathToLastCord.end())
                            {
                                set<Cord> newPathToLastCord = pathToLastCord;
                                newPathToLastCord.insert(Cord(i,j));
                                c->pathMap[Cord(i,j-1)].push_back(newPathToLastCord);
                            }
                            if (OnBoard(i,j+1,m,n) && board[i][j+1] == 'a' + letter && pathToLastCord.find(Cord(i,j+1)) == pathToLastCord.end())
                            {
                                set<Cord> newPathToLastCord = pathToLastCord;
                                newPathToLastCord.insert(Cord(i,j));
                                c->pathMap[Cord(i,j+1)].push_back(newPathToLastCord);
                            }
                        }
                    }

                    if (!c->pathMap.empty())
                    {
                        // cout<<"  "<<c->cc<<endl;
                        trieDfsWalk.push(c);
                    }
                }
            }
            delete frontier;
        }

        return res;
    }

private:
    bool OnBoard(int i, int j, int m, int n)
    {
        return (!(i < 0 || i >= m || j < 0 || j >= n));
    }
};