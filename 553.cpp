#define __USE_MINGW_ANSI_STDIO 0
#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    string optimalDivision(vector<int>& nums) 
    {
    	string res;
    	int l = nums.size();
    	
    	if (l == 0)
    	{
    		return res;
    	}
    	res += to_string(nums[0]);

    	if (l == 1)
    	{
    		return res;
    	}
    	else if (l == 2)
    	{
    		res += "/" + to_string(nums[1]);
    		return res;
    	}
    	else
    	{
    		res += "/("+to_string(nums[1]);
    		for (int i = 2; i < l ; i++)
    		{
    			res += "/" + to_string(nums[i]);
    		}
    		res += ")";
    		return res;
    	}

    }
};

int main(int argc, char const *argv[])
{
	Solution mySol;
	vector <int> v = {1,2,3,4,5,6,7,8};
	string s = mySol.optimalDivision(v);
	cout<<s<<endl;
	return 0;
}