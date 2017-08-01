#include <vector>
#include <list>
#include <iostream>

using namespace std;

class Solution 
{
public:
    bool canJump(vector<int>& nums) 
    {
    	int l = nums.size();
        vector <bool> visited (l, false);
        list <int> dfsStack;
        dfsStack.push_back(0);
        visited[0] = true;
        int horizon = 0;
        while (!dfsStack.empty())
        {
        	int frontier = dfsStack.back();
        	dfsStack.pop_back();
        	int j = frontier + nums[frontier];
        	
        	if (j >= l -1)
        	{
        		return true;
        	}
        	
        	if (j < horizon)
        	{
        		continue;
        	}
        	else
        	{
        		horizon = j;
        	}
        	
        	for (int i = frontier + 1; i <= j; i++)
        	{
        		if (!visited[i])
        		{
        			dfsStack.push_back(i);
        			visited[i] = true;
        		}
        	}
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}