#define __USE_MINGW_ANSI_STDIO 0
#include <string>
#include <iostream>
#include <memory>
#include <list>
#include <sstream>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
    	string res = string();
    	list<TreeNode*> stack;
    	stack.push_back(root);
    	while (!stack.empty()){
    		TreeNode* frontier = stack.back();
    		stack.pop_back();

    		if (frontier == NULL){
    			res += "N";
    		}
    		else {
    			res += to_string(frontier->val);
    			stack.push_front(frontier->left);
    			stack.push_front(frontier->right);
    		}
    		res += "-";
    	}
    	return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector <string> nodesAsStringInBfsSequence;
        stringstream sstr(data);
        string str;
        while (getline(sstr,str,'-')){
        	nodesAsStringInBfsSequence.push_back(str);
        }
        for (auto n: nodesAsStringInBfsSequence){
        	cout<<n<<endl;
        }
        TreeNode * res = nullptr;
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

int main(int argc, char const *argv[])
{
	TreeNode * root = new TreeNode(1);
	TreeNode * a = new TreeNode(2);
	TreeNode * b = new TreeNode(3);
	TreeNode * d = new TreeNode(4);
	TreeNode * e = new TreeNode(5);
	TreeNode * f = new TreeNode(6);
	root->left	=	a;
	root->right =	b;
	a->left		=	d;
	b->right	=	e;
	e->right 	=	f;
	Codec codec;
	string s = codec.serialize(root);
	cout<<s<<endl;
	codec.deserialize(s);
	return 0;
}