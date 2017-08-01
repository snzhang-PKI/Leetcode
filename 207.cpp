// 用递归写dfs也有好处 finishing time容易加
// 用循环写dfs的话，要想加finishing time 需要判断一下 是不是还有有效的child存在 若存在 则入栈 若不存在 更新finishing time
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

class Solution 
{
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) 
    {
        unordered_map <int,unordered_set<int>> edgeList;
        vector <int> courseStatus (numCourses, 0);
        // node status: 0 - not visited, 1 discoverd, 2 finished

        for (auto e : prerequisites)
        {
        	edgeList[e.first].insert(e.second);
        }

        for (int course = 0; course < numCourses; course++)
        {
        	// cout<<course<<endl;
        	if (courseStatus[course] == 0)
        	{
        		stack <int> dfsStack;
        		dfsStack.push(course);

        		
        		while (!dfsStack.empty())
        		{
        			int frontier = dfsStack.top();
        			courseStatus[frontier] = 1;
        			int childNotVisited = 0;
        			if (!edgeList[frontier].empty())
        			{
	        			for (auto child : edgeList[frontier])
	        			{
	        				cout<<frontier<<" "<<child<<endl;
	        				cout<<"courseStatus[child]: "<<courseStatus[child]<<endl;   	

	        				if (courseStatus[child] == 1)
	        				{
	        					return false;
	        				}
	        				else if (courseStatus[child] == 0)
	        				{
	        					childNotVisited++;
	        					dfsStack.push(child);
	        				}
	        			}
	        		}
	        		if (childNotVisited == 0)
	        		{
	        			courseStatus[frontier] = 2;
	        			dfsStack.pop();
	        		}

        		}
        	}
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
	Solution mySol;
	vector <pair<int,int>> v = {pair<int,int>(0,1),
								pair<int,int>(3,1),
								pair<int,int>(1,3),
								pair<int,int>(3,2)};
	int n = 4;
	cout<<mySol.canFinish(n,v)<<endl;
	return 0;
}