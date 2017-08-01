//把向量复制来复制去是很耽误时间的 可以用helper函数 记录首尾的位置来避免这一问题
//有些时候 题目本身设计的函数接口并不是最优的
#include <vector>
#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution 
{
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
    	int l = inorder.size();
    	if (l == 0)
    	{
    		TreeNode* res = nullptr;
    		return res;
    	}
    	else
    	{
    		int val = preorder[0];
	        TreeNode* res = new TreeNode(val);
	        int i;

	        for (i = 0; i < l; i++)
	        {
	        	if (inorder[i] == val)
	        	{
	        		break;
	        	}
	        }
	        // cout<<i<<l<<endl;
	        if (i > 0)
	        {
	        	vector<int> leftPre(preorder.begin() + 1, preorder.begin() + i + 1);
	        	vector<int> leftIn(inorder.begin(), inorder.begin() + i);
	        	res->left = buildTree(leftPre, leftIn);
	        }
	        // cout<<"!"<<endl;
	        if (i < l - 1)
	        {
	        	vector<int> rightPre(preorder.begin() + i + 1, preorder.end());
	        	vector<int> rightIn(inorder.begin() + i + 1, inorder.end());
	        	res->right = buildTree(rightPre, rightIn);
	        }
	        return res;
    	}

    }
};

int main(int argc, char const *argv[])
{
	vector <int> pre = {1,2};
	vector <int> in = {2,1};
	Solution mySol;
	auto r = mySol.buildTree(pre,in);
	cout<<r->val<<endl;
	cout<<r->left->val<<endl;
	// cout<<r->right->val<<endl;
	return 0;
}