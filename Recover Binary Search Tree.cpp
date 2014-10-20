//
//description:
//二叉搜索树有两个值交换了，求恢复原数
//
//solution:
//中序查找，中序就是顺序的
//有两种情况需要考虑，一种就是前后交换
//一种是隔着交换的
//所以需要两个值，记录交换的
//如果A[i]>A[i+1]，A[i+1]是错误的
//用一个prev记录上一个结果
 
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<algorithm>

using namespace std;


struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode *s1,*s2,*pre;
    void recoverTree(TreeNode *root) {
    	vector<TreeNode *> errNodes;
    	s1=s2=pre=NULL;
    	findErr(root);
    	swap(s1->val,s2->val);
    }
    
    void findErr(TreeNode * root){
    	if(root == NULL)
    		return;
    	findErr(root->left);
    	if(pre&&pre->val > root->val){
    		if(s1 == NULL){
    			s1 = pre;
    			s2 = root;
    		}else
    			s2 = root;
    	}
    	pre = root;
    	findErr(root->right);
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
	
	TreeNode * node1 = new TreeNode(2);
	TreeNode * node2 = new TreeNode(3);
	TreeNode * node3 = new TreeNode(1);
	
	
	node1->right = node2;
	node2->left = node3;
	s.inorderTraverse(node1);
	cout<<endl;
	 
	s.recoverTree(node1);
	s.inorderTraverse(node1);
	cout<<endl;
}
