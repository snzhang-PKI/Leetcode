#include <iostream>
#include <list>

using namespace std;




class Solution {
public:
    int findKthNumber(int n, int k) {
    	int res = 1;
    	k--;
    	while (k > 0)
    	{
    		int count = 0;
    		for (long long first = res, last = first + 1; first <= n; first *= 10, last *= 10)
    		{
    			count += min(n + 1LL, last) - first;
    		}
    		if (k >= count)
    		{
    			res ++;
    			k -= count;
    		}
    		else
    		{
    			res *= 10;
    			k --;
    		}
    	}
    	return res;
    }

private:

	int NDigitOne(int n)
	{
		int res = 1;
		for (int i = 1; i < n; i++)
		{
			res = res * 10 + 1;
		}
		return res;
	}
};

int main(int argc, char const *argv[])
{
	Solution mySol;
	cout<<mySol.findKthNumber(13,2)<<endl;
	return 0;
}