//标记完0之后填充的时候 遍历所有的格子并检查行首/列首 要比 遍历首行ang首列 要好， worst case 前者是后者的两倍时间

#include <vector>
#include <iostream>

using namespace std;

class Solution 
{
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
    	int m = matrix.size();
    	if (m)
    	{
    		int n = matrix[0].size();
    		if (n)
    		{
    			bool zeroFirstRow = false, zeroFirstColumn = false;

    			for (int i = 0; i < m; i++)
    			{
    				if (matrix[i][0] == 0)
    				{
    					zeroFirstColumn = true;
    					break;
    				}
    			}

    			for (int i = 0; i < n; i++)
    			{
    				if (matrix[0][i] == 0)
    				{
    					zeroFirstRow = true;
    					break;
    				}
    			}

    			for (int i = 0; i < m; i++)
    			{
    				for (int j = 0; j < n; j++)
    				{
    					if (matrix[i][j] == 0)
    					{
    						matrix[i][0] = 0;
    						matrix[0][j] = 0;
    					}
    				}
    			}

    			for (int i = 1; i < m ; i++)
    			{
    				if (matrix[i][0] == 0)
    				{
    					for (int t = 1 ; t < n ; t++)
    					{
    						matrix[i][t] = 0;
    					}
    				}
    			}

    			for (int j = 1; j < n; j++)
    			{
    				if (matrix[0][j] == 0)
    				{
    					for (int t = 1; t < m; t++)
    					{
    						matrix[t][j] = 0;
    					}
    				}
    			}

    			if (zeroFirstRow)
    			{
    				for (int i = 0; i < n; i++)
    				{
    					matrix[0][i] = 0;
    				}
    			}

    			if (zeroFirstColumn)
    			{
    				for (int i = 0; i < m; i++)
    				{
    					matrix[i][0] = 0;
    				}
    			}
    		}
    	}
    }
};

int main(int argc, char const *argv[])
{
	Solution mySol;
	vector<vector<int>> v = {{1,0,0,5},{4,3,1,4},{0,1,1,4},{1,2,1,3},{0,0,1,1}};
	mySol.setZeroes(v);
	return 0;
}