#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int numberOfArithmeticSlices(vector<int>& A) 
    {
    	int l = A.size();
        int dp = 0;
        int res = 0;
        for (int i= 2; i < l; i++)
        {
        	if (A[i] - A[i-1] == A[i-1] - A[i-2])
        	{
        		dp = dp + 1;
        		res += dp;
        	}
        }
        return res;

    }
};

int main(int argc, char const *argv[])
{
	Solution mySol;
	vector<int> v = {1,2,3,4};
	int res = mySol.numberOfArithmeticSlices(v);
	cout<<res<<endl;
	return 0;
}