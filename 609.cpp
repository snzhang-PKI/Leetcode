#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution 
{
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) 
    {
    	unordered_map<string,vector<string>> m;
    		
    	for (auto line : paths)
    	{
    		stringstream sstr(line);
    		string dirPath;
    		sstr >> dirPath;
    		dirPath += '/';
    		string file;
    		while (sstr >> file)
    		{
    			int p = file.find("(");
    			int q = file.find(")");
    			string fullPath = dirPath + file.substr(0, p);
    			string content = file.substr(p + 1, q - p - 1);
    			m[content].push_back(fullPath);
    		}
    	}

        vector<vector<string>> res;

    	for (auto entry : m)
    	{
    		if (entry.second.size() > 1)
    		{
    			res.push_back(entry.second);
    		}
    	}

        return res;
    }
};
int main(int argc, char const *argv[])
{
	Solution mySol;
	vector <string> v = {"root/a 1.txt(abcd) 2.txt(efgh)", "root/c 3.txt(abcd)", "root/c/d 4.txt(efgh)", "root 4.txt(efgh)"};
	mySol.findDuplicate(v);
	return 0;
}