//
//description:
//每一个根节点到也叶子节点表示一个数，求所有数之和
//
//solution:
 
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
	int sum = 0;
    int sumNumbers(TreeNode *root) {
    	if(root == NULL)
    		return 0;
        preorder(root,0);
        
        return sum;
    }
    
    void preorder(TreeNode * root,int val){
    	val = val * 10 + root->val;
    	if(root->left == NULL && root->right == NULL){
    		sum += val;
    	}else{
    		if(root->left != NULL)
    			preorder(root->left,val);
    		if(root->right != NULL)
    			preorder(root->right,val);
    	}
    }
};

int main(){
	
} 
