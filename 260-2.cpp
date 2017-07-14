//位操作同样是O(n) 但是空间只要O（1）
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int diff = 0;
        
        for (int n : nums)
        {
        	diff ^= n;
        }

        diff &= -diff;
        vector<int> res = {0,0};
        
        for (int n : nums)
        {
        	if (n & diff)
        	{
        		res[0] ^= n;
        	}
        	else
        	{
        		res[1] ^=n;
        	}
        }

        return res;
    }
};

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}