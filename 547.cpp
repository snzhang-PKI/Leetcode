#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    int findCircleNum(vector<vector<int>>& M)
    {
        int totalStudentNumber = M.size();
        vector <int> visited = vector <int> (totalStudentNumber, 0);
        int res = 0;
        for(int i = 0; i < totalStudentNumber; i++)
        {
        	if (!visited[i])
        	{
        		res ++;
        		stack <int> dfsStack;
        		dfsStack.push(i);
        		while (!dfsStack.empty())
        		{
        			int frontier = dfsStack.top();
        			dfsStack.pop();
        			for (int j = 0; j < totalStudentNumber; j++)
        			{
        				if (!visited[j] && M[frontier][j])
        				{
        					dfsStack.push(j);
        					visited[j] = 1;
        				}
        			}
        		} 
        	}
        	else
        	{
        		continue;
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