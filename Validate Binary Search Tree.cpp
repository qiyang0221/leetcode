#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;


  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:
    bool isValidBST(TreeNode *root) {
    	TreeNode * prev = NULL;
        return inOrderTraversal(root,prev);
    }
    
    bool inOrderTraversal(TreeNode * root,TreeNode * &prev){
    	if(root == NULL)
    		return true;
		if(!inOrderTraversal(root->left,prev))
			return false;
			
		if(prev != NULL){
			if(prev->val >= root->val )
				return false;
		}
		prev = root;
		if(!inOrderTraversal(root->right,prev))
			return false;
		return true;
    }
};

int main(){
	Solution s;
	
	TreeNode * node1 = new TreeNode(1);
	TreeNode * node2 = new TreeNode(2);
	TreeNode * node3 = new TreeNode(3);
	node2->left = node1;
	node2->right = node3;
	
	if(s.isValidBST(node2))
		cout<<"true"<<endl;
	else
		cout<<"false"<<endl;
} 
