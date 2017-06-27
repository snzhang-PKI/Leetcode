#include <iostream>

using namespace std;

struct TreeNode {
    int val;
	TreeNode *left;
	TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr){
        	return t2;
        }
        else if (t2 == nullptr){
        	return t1;
        }
        else {
        	TreeNode* res = new TreeNode(t1->val+t2->val);
        	res->left = mergeTrees(t1->left,t2->left);
        	res->right = mergeTrees(t1->right,t2->right);
        	return res;
        }
    }
};

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}