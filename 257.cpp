//Definition for a binary tree node.
#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : 
    	val(x),
    	left(nullptr), 
    	right(nullptr) 
    {
    }
};

class Solution 
{
public:
    vector<string> binaryTreePaths(TreeNode* root) 
    {
        vector<string> res;
        if (root == nullptr)
        {
        	return res;
        }
        else if (root->left == nullptr && root -> right == nullptr)
        {
        	res.push_back(to_string(root -> val));
        	return res;
        }
        else 
        {
        	if (root->left != nullptr)
        	{
	        	for (auto str : binaryTreePaths(root -> left))
	        	{
	        		res.push_back(to_string(root -> val)+"->"+str);
	        	}
	        }
	        if (root -> right != nullptr)
	        {
	        	for (auto str : binaryTreePaths(root -> right))
	        	{
	        		res.push_back(to_string(root -> val)+"->"+str);
	        	}
	        }
	        return res;
        }
    }
};

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}