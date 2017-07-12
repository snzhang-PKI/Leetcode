#include <vector>
#include <queue>
#include <iostream>
#include "limits.h"

using namespace std;

struct node
{
public:
	int row;
	int index;
	int val;
	node(int r, int i, int v):
		row(r),
		index(i),
		val(v)
		{}
};

class mycomparison
{
public:
	bool operator() (const node& x, const node& y) const
	{
		return x.val > y.val;
	}
};

class Solution 
{
public:
    vector<int> smallestRange(vector<vector<int>>& nums) 
    {
    	vector <int> res;
    	int minVal;
    	int maxVal = INT_MIN;
    	priority_queue <node, vector<node>, mycomparison> frontierQueue;
    	int l = nums.size();

    	for (int i = 0; i < l; i++)
    	{
    		if (nums[i][0] > maxVal)
    		{
    			maxVal = nums[i][0];
    		}

    		frontierQueue.push(node(i,0,nums[i][0]));
    	}

    	minVal = frontierQueue.top().val;
    	node topNode = frontierQueue.top();
    	res = {minVal, maxVal};

    	while (topNode.index < nums[topNode.row].size() - 1)
    	{
    		if (nums[topNode.row][topNode.index + 1] > maxVal)
    		{
    			maxVal = nums[topNode.row][topNode.index + 1];
    		}

    		frontierQueue.pop();
    		frontierQueue.push(node(topNode.row, topNode.index + 1, nums[topNode.row][topNode.index + 1]));
    		topNode = frontierQueue.top();
    		minVal = frontierQueue.top().val;
// cout<<1<<endl;
    		if (maxVal - minVal < res[1] - res[0])
    		{
    			res = {minVal, maxVal};
    		}
// cout<<2<<endl;
    	}
    	return res;
        
    }
};

int main(int argc, char const *argv[])
{
    // priority_queue <node, vector<node>, mycomparison> frontierQueue;
    // node a(1,1,2);
    // node b(1,1,3);
    // frontierQueue.push(a);
    // frontierQueue.push(b);
    // cout<<frontierQueue.top().val<<endl;
    // frontierQueue.pop();
    // cout<<frontierQueue.top().val<<endl;
	/* code */
	Solution mySol;
	vector<int> a = {1,2,3};
	vector<int> b = {4,5,6};
	vector<vector<int>> v = {{4,10,15,24,26}, {0,9,12,20}, {5,18,22,30}};
	auto res = mySol.smallestRange(v);
	for (auto i : res)
	{
		cout<<i<<" ";
	}
	cout<<endl;


	return 0;
}