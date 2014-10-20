//
//description:
//中序遍历树，要求O(1)空间，O(n)时间
//
//solution:
//这里用到了是morris树遍历方法：
//如果当前点左子树为空，那么访问右子树，
//如果不为空，则找到当前左子树的最右叶节点，即当前节点前驱
//用左子树的最右叶节点的rchild链接到当前节点
//然后继续访问左子树
//如果一个节点查找前驱时指向了自己，说明前驱已经构造好了，将前驱指向自己的指针设置为NULL
//同时访问右子树
//
//这里分析一下O(n)时间:
//查找前驱的过程，其实就相当于访问了整棵树，然后根据根据前驱访问到自己的时候再查找了一遍前驱，
//所以总共对数访问了两次，总时间为2n,复杂度为O(n) 

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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        while(root != NULL){
        	if(root->left ==  NULL){
        		res.push_back(root->val);
        		root = root->right;
        	}else{
        		TreeNode * tmp = root->left;
        		while(tmp->right != NULL && tmp->right != root)
        			tmp = tmp->right;
        		if(tmp->right == NULL){
        			tmp->right = root;
        			root = root->left;
        		}else{
        			tmp->right = NULL;
        			res.push_back(root->val);
        			root = root->right;
        		}
        	}
        }
        
        return res;
    }
};


int main(){
	Solution s;
	TreeNode * node1 = new TreeNode(1);
	TreeNode * node2 = new TreeNode(2);
	TreeNode * node3 = new TreeNode(3);
	TreeNode * node4 = new TreeNode(4);
	
	node1->left = node2;
	node1->right = node3;
	node3->left = node4;
	
	vector<int> res = s.inorderTraversal(node1);
	for(int i=0;i<res.size();i++)
		cout<<res[i]<<" ";
	cout<<endl; 
}
