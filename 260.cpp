#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution 
{
public:
    vector<int> singleNumber(vector<int>& nums) 
    {
        unordered_set <int> s;

        for (auto n:nums)
        {
        	if (s.find(n) == s.end())
        	{
        		s.insert(n);
        	}
        	else
        	{
        		s.erase(n);
        	}
        }

        vector<int> res;

        for (auto n:s)
        {
        	res.push_back(n);
        }

        return res;
    }
};

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}