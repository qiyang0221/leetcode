//
//description:
//将一个有序的数组转换为二叉查找树
//
//solution:
//二分，left,right 


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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        int size= num.size();
        TreeNode * root = NULL;
        if(size<0)
        	return root;
        root = buildTree(num,0,size);
        
        return root;
    }
    
    TreeNode * buildTree(vector<int> &num,int start,int end){
    	if(start >= end)
    		return NULL;
    	int mid = (start + end) / 2;
    	TreeNode * root = new TreeNode(num[mid]);
    	root->left = buildTree(num,start,mid);
    	root->right = buildTree(num,mid+1,end);
    	
    	return root;
    }
    
    void inorderTraverse(TreeNode * root){
    	if(root == NULL)
    		return;
    	inorderTraverse(root->left);
    	cout<<root->val<<" ";
    	inorderTraverse(root->right);
    }
};



int main(){
	Solution s;
	vector<int> num;
	num.push_back(1);
	num.push_back(2);
	num.push_back(3);
	num.push_back(4);
	num.push_back(5);
	num.push_back(6);
	num.push_back(7);
	
	TreeNode * root = s.sortedArrayToBST(num);
	if(root == NULL)
		cout<<"root NULL"<<endl;
	s.inorderTraverse(root);
	cout<<endl;
}
