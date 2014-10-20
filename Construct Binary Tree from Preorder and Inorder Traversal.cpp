//
//description:
//先序和中序构造二叉树
//
//solution
//先序中序各用两个变量表示起始终止
//先序的第一个就是中序的中间值 

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>

using namespace std;



struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    	int size = preorder.size();
        TreeNode * root = recur(preorder,0,size,inorder,0,size);
        
        return root;
    }
    
    TreeNode *recur(vector<int> &preorder,int pre_start,int pre_end,vector<int> &inorder,int in_start,int in_end){
    	if(in_start == in_end || pre_start == pre_end)
    		return NULL;
    	TreeNode * root = new TreeNode(preorder[pre_start]);
    	int mid;
    	for(mid=in_start;inorder[mid] != preorder[pre_start];mid++);
    	int len1 = mid - in_start;
    	root->left = recur(preorder,pre_start+1,pre_start+len1+1,inorder,in_start,mid);
    	root->right = recur(preorder,pre_start+len1+1,pre_end,inorder,mid+1,in_end);
    	
    	return root;
    }
    
    void inorderTraverse(TreeNode * root){
    	if(root == NULL)
    		cout<<"# ";
    	else{
    		inorderTraverse(root->left);
	    	cout<<root->val<<" ";
	    	inorderTraverse(root->right);
    	}
    }
};


int main(){
	Solution s;
	vector<int> preorder,inorder;
	preorder.push_back(4);
	preorder.push_back(2);
	preorder.push_back(1);
	preorder.push_back(3);
	preorder.push_back(6);
	preorder.push_back(5);
	preorder.push_back(7);
	
	inorder.push_back(1);
	inorder.push_back(2);
	inorder.push_back(3);
	inorder.push_back(4);
	inorder.push_back(5);
	inorder.push_back(6);
	inorder.push_back(7);
	
	TreeNode * root = s.buildTree(preorder,inorder);
	s.inorderTraverse(root);
}
