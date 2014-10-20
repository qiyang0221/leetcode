//
//description:
//先序访问,O(n)时间，O(1)空间
//
//solution:
//当前右子树的前驱是当前左子树的最右节点且右孩子为空
//将该右孩子指向右子树
//迭代访问 


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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        while(root != NULL){
        	if(root->left == NULL){
        		res.push_back(root->val);
        		root = root->right;
        	}else{
        		TreeNode * tmp = root->left;
        		while(tmp->right != NULL && tmp->right != root)
        			tmp = tmp->right;
        		if(tmp->right == NULL){
        			res.push_back(root->val);
        			tmp->right = root;
        			root = root->left;
        		}else{
        			tmp->right = NULL;
        			root = root->right;
        		}
        	}
        }
        
        return res;
    }
};


int main(){
	Solution s;
	TreeNode * node1 = new TreeNode(3);
	TreeNode * node2 = new TreeNode(1);
	TreeNode * node3 = new TreeNode(2);
	//TreeNode * node4 = new TreeNode(4);
	node1->left = node2;
	node2->right = node3;
	//node3->right = node4;
	
	vector<int> res = s.preorderTraversal(node1);
	for(int i=0;i<res.size();i++)
		cout<<res[i]<<" ";
}
