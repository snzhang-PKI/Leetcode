#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution 
{
public:
    int hIndex(vector<int>& citations) 
    {
    	sort(citations.begin(), citations.end());
    	reverse(citations.begin(),citations.end());
    	int l = citations.size();
    	int i;
    	for (i = 0; i < l; i++)
    	{
    		if (citations[i] < i + 1)
    		{
    			break;
    		}

    	}
        return i;
    }
};

int main(int argc, char const *argv[])
{
	vector <int> v = {3,0,6};
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	for (auto i : v)
	{
		cout<<i<<" ";
	}
	cout<<endl;
	return 0;
}