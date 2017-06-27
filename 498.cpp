#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
    	vector<int> res;
    	int m = matrix.size();
    	if (m != 0)
    	{
    		int n = matrix[0].size();
    		if (n != 0)
    		{
    			int l = m + n -2;
    			for (int sum = 0; sum <= l; sum++)
    			{
    				// upright
    				if (sum%2 == 0)
    				{
    					int i = min(sum, m - 1);
    					int j = sum - i;
    					while ( i >= 0 && j < n)
    					{
    						res.push_back(matrix[i][j]);
    						i --;
    						j ++;
    					}
    				}
    				//downleft
    				else
    				{
    					int j = min(sum, n - 1);
    					int i = sum - j;
    					while ( i < m && j >= 0)
    					{
    						res.push_back(matrix[i][j]);
    						i ++;
    						j --;
    					}
    				}
    			}
    		}
    	}
        return res;
    }
};

int main(int argc, char const *argv[])
{
	Solution mySol;
	vector<vector<int>> m = {{6},{9},{7}};
	vector<int> res = mySol.findDiagonalOrder(m);
	for (auto r:res)
	{
		cout<<r<<" ";
	}
	cout<<endl;
	return 0;
}