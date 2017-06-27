/*链表或者二叉树的问题 在维护当前要处理的节点的同时 最好也维护其父节点 以方便删除操作
 *
 *
 *
 *
 *
 */




// Definition for a binary tree node.
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
    TreeNode* deleteNode(TreeNode* root, int key) {
    	TreeNode* target = root;
        return root;
    }

	void printTree(TreeNode* root){
		if (root == nullptr){
			cout<<" n";
		}
		else {
			cout<<" "<<root->val;
			printTree(root->left);
			printTree(root->right);
		}
	}
};

int main(int argc, char const *argv[])
{
	TreeNode* root = new TreeNode(7);
	TreeNode* a = new TreeNode(5);
	root->left = a;
	// TreeNode* b = new TreeNode(9);
	// root->right = b;
	// TreeNode* c = new TreeNode(4);
	// a->left = c;
	// TreeNode* d = new TreeNode(6);
	// a->right = d;
	// TreeNode* e = new TreeNode(8);
	// b->left = e;
	// TreeNode* f = new TreeNode(10);
	// b->right = f;
	Solution mysol;
	root = mysol.deleteNode(root,7);
	mysol.printTree(root);
	return 0;
}