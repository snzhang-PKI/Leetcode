#include <iostream>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
    	if (x < 0)
    	{
    		cout<<"please review math 101 and come back later."<<endl;
    		return -1;
    	}
    	else if (x == 1)
    	{
    		return 1;
    	}
    	else 
    	{
			return betterSqrt(x, 0, x);
		}
    }

private:

    int betterSqrt(const int &x, int left, int right)
    {
    	if (right - left <= 1)
    	{
    		return left;
    	}
    	else
    	{
    		int mid = (left + right) / 2;
    		long long tmp = (mid + 0LL) * mid;
    		if(tmp < x)
    		{
    			return betterSqrt(x, mid, right);
    		}
    		else if (tmp > x)
    		{
    			return betterSqrt(x, left, mid);
    		}
    		else
    		{
    			return mid;
    		}
    	}
    }
};

int main(int argc, char const *argv[])
{
	Solution mySol;
	cout<<mySol.mySqrt(100)<<endl;
	return 0;
}