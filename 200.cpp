#include <vector>
#include <iostream>
#include <stack>

using namespace std;

class Solution 
{
public:
    int numIslands(vector<vector<char>>& grid) 
    {
        int res = 0;
        int m = grid.size();
        
        if (m)
        {
        	int n = grid[0].size();
        	if (n)
        	{
        		for (int i = 0 ; i < m; i++)
        			for (int j = 0; j < n; j++)
        			{
        				if (grid[i][j] == '1')
        				{
        					res ++;
        					//check all grid[i][j]'s neighbour
        					stack<pair<int,int>> dfsWalkTheIsland;
        					dfsWalkTheIsland.push(pair<int,int>(i,j));
        					while (!dfsWalkTheIsland.empty())
        					{
        						pair<int,int> frontier = dfsWalkTheIsland.top();
        						dfsWalkTheIsland.pop();
        						int p = frontier.first, q = frontier.second;

        						if (InGrid(p-1,q,m,n) && grid[p-1][q] == '1') {dfsWalkTheIsland.push(pair<int,int>(p-1,q)); grid[p-1][q] = '0';}
        						if (InGrid(p+1,q,m,n) && grid[p+1][q] == '1') {dfsWalkTheIsland.push(pair<int,int>(p+1,q)); grid[p+1][q] = '0';}
        						if (InGrid(p,q-1,m,n) && grid[p][q-1] == '1') {dfsWalkTheIsland.push(pair<int,int>(p,q-1)); grid[p][q-1] = '0';}
        						if (InGrid(p,q+1,m,n) && grid[p][q+1] == '1') {dfsWalkTheIsland.push(pair<int,int>(p,q+1)); grid[p][q+1] = '0';}
        					}
        				}
        			}
        	}
        }

        return res;
    }
private:
	bool InGrid(int i, int j , int m, int n)
	{
		if (i < 0 || i >= m || j < 0 || j >= n)	return false;
		else	return true;
	}
};

int main(int argc, char const *argv[])
{
	
	return 0;
}