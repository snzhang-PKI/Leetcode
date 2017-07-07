#include <iostream>
#include <vector>

using namespace std;


class Solution 
{
public:
    int hIndex(vector<int>& citations) 
    {
    	int l = citations.size();
    	if (l == 0)	return 0;
        int i = 0;
        int j = l - 1;
        int mid = (i + j) / 2;
        while (i < j)
        {
        	cout<<i<<j<<mid<<endl;
        	if (citations[mid] < l - mid)
        	{
        		i = mid + 1;
        		mid = (i + j) / 2;
        	}
        	else
        	{
        		j = mid;
        		mid = (i + j) / 2;
        	}
        }
        if (citations[mid] < l - mid)
        {
        	return l - mid - 1;
        }
        else
        {
        	return l - mid;
        }
        
    }
};

int main(int argc, char const *argv[])
{
	Solution mySol;
	vector<int> v = {0,0,1};
	cout<<mySol.hIndex(v)<<endl;
	return 0;
}