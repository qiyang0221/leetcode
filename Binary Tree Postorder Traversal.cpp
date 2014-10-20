//
//description:
//使用O(n)时间，O(1)空间后序遍历
//
//solution:
//这里也采用morris方法：
//但是后序比较奇怪，当前节点在右孩子的最右且右孩子为空的节点之后输出
//而且做子树的前驱是上一个节点的左孩子的最右节点
//那么进入到子树，我们就需要回过头访问根节点，空间肯定比O(1)大
//所以巧妙的引入了一个新的根节点，这个根节点的左子树指向原来的根节点
//采用中序，当前节点，到其先序节点，是后序的倒序,打印的时候需要交换顺序 
 
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<algorithm>

using namespace std;

struct TreeNode{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
    	vector<int> res;
    	TreeNode * dump = new TreeNode(0);
    	dump->left = root;
    	TreeNode * cur = dump;
        while(cur != NULL){
        	if(cur->left == NULL){
        		cur = cur->right;
        	}else{
        		TreeNode * tmp = cur->left;
        		while(tmp->right != NULL && tmp->right != cur)
        			tmp = tmp->right;
        		if(tmp->right == NULL){
        			tmp->right = cur;
        			cur = cur->left;
        		}else{
        			addVal(res,cur->left,tmp);
        			tmp->right = NULL;
        			cur = cur->right;
        		}
        	}
        }
        
        return res;
    }
    
    void addVal(vector<int> &res,TreeNode *from,TreeNode *to){
    	vector<int> line;
    	TreeNode * cur = from;
    	while(true){
    		line.insert(line.begin(),cur->val);
    		if(cur == to)
    			break;
    		cur = cur->right;
    	}
    	for(int i=0;i<line.size();i++)
    		res.push_back(line[i]);
    }
};


int main(){
	/*TreeNode * node1 = new TreeNode(1);
	TreeNode * node2 = new TreeNode(2);
	TreeNode * node3 = new TreeNode(3);
	TreeNode * node4 = new TreeNode(4);
	TreeNode * node5 = new TreeNode(5);
	TreeNode * node6 = new TreeNode(6);
	TreeNode * node7 = new TreeNode(7);
	TreeNode * node8 = new TreeNode(8);
	TreeNode * node9 = new TreeNode(9);*/
	
	/*node9->left = node5;
	node9->right = node8;
	node5->left = node1;
	node5->right = node4;
	node4->left = node2;
	node4->right = node3;
	node8->right = node7;
	node7->left = node6;*/
	
	TreeNode * node1 = new TreeNode(1);
	TreeNode * node2 = new TreeNode(2);
	
	node1->right = node2;
	
	Solution s;
	vector<int> res = s.postorderTraversal(node1);
	for(int i=0;i<res.size();i++)
		cout<<res[i]<<" ";
	cout<<endl; 
}
