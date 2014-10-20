//
//description:
//层序访问树
//
//solution:
//非递归都会，递归这里利用两个vector<vector<int>>，行表示层次
//这样用dfs访问就可以将访问的节点插入的相应的位置 

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<queue> 

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
    	vector<vector<int> > res;
    	if(root == NULL)
    		return res;
        queue<TreeNode*> q;
        queue<TreeNode*> qq;
        
        q.push(root);
        while(!q.empty()){
        	vector<int> line;
        	while(!q.empty()){
        		TreeNode * node = q.front();
        		line.push_back(node->val);
        		qq.push(q.front());
        		q.pop();
        	}
        	res.push_back(line);
        	while(!qq.empty()){
        		TreeNode * root = qq.front();
        		if(root->left != NULL)
        			q.push(root->left);
        		if(root->right != NULL)
        			q.push(root->right);
        		qq.pop();
        	}
        }
        
        return res;
    }
};


int main(){
	Solution s;
	
	TreeNode * node1 = new TreeNode(3);
	TreeNode * node2 = new TreeNode(9);
	TreeNode * node3 = new TreeNode(20);
	TreeNode * node4 = new TreeNode(15);
	TreeNode * node5 = new TreeNode(7);
	node1->left = node2;
	node1->right = node3;
	node3->left = node4;
	node3->right = node5;
	
	vector<vector<int> > res= s.levelOrder(node1);
	for(int i=0;i<res.size();i++){
		for(int j=0;j<res[i].size();j++){
			cout<<res[i][j]<<" ";
		}
		cout<<endl;
	}
}
