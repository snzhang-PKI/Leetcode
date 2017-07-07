#define __USE_MINGW_ANSI_STDIO 0
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector <string> keys = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

class Solution 
{
public:
    vector<string> letterCombinations(string digits) 
    {
    	vector <string> res;
    	int l = digits.size();

    	if (l == 1)
    	{
    		for (auto c : keys[digits[0]- '0'-2])
			{
				string temp = "";
 				res.push_back(temp+c);
   			}
    	}
    	else if (l > 1)
    	{
    		string pre = digits.substr(0, l - 1);
    		int tail = digits[l-1] - '0';
    		vector <string> preCombination = letterCombinations (pre);
    		for (auto str : preCombination)
    		{
    			for (auto c : keys[tail - 2])
    			{
    				res.push_back(str+c);
    			}
    		}
    	}
    	return res;
    }
};

int main(int argc, char const *argv[])
{
	Solution mySol;
	auto v = mySol.letterCombinations("");
	// for (auto s : v)
	// {
	// 	cout<<s<<endl;
	// }
	return 0;
}