//
//description:
//��������չ�����һ����
//
//solution:
//�����һ����Ӧ�÷�ӳ�������������Ȼ����һ��prev��¼ǰһ���ڵ�
//�����ĿҲ�����õ����ķ���
//����stack��¼ջ���ȷ��Һ����ٷ����ӣ�Ȼ��ǰ�ڵ����Ӷ����ڵ�
 
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
    void flatten(TreeNode *root) {
    	if(root == NULL)
    		return;
    	TreeNode * prev = NULL;
        preOrderTraversal(root,prev);
    }
    
    void preOrderTraversal(TreeNode * root,TreeNode * &prev){
    	if(prev != NULL){
    		prev->right = root;
    	}
    	TreeNode * l = root->left;
    	TreeNode * r = root->right;
    	
    	root->left = NULL;
    	prev = root;
    	if(l != NULL)
    		preOrderTraversal(l,prev);
    	
    	if(r != NULL)
    		preOrderTraversal(r,prev);
    }
};

int main(){
	TreeNode * node1 = new TreeNode(1);
	TreeNode * node2 = new TreeNode(2);
	TreeNode * node3 = new TreeNode(5);
	TreeNode * node4 = new TreeNode(3);
	TreeNode * node5 = new TreeNode(4);
	TreeNode * node6 = new TreeNode(6);
	
	node1->left = node2;
	node1->right = node3;
	node2->left = node4;
	node2->right = node5;
	node3->right = node6;
	
	Solution s;
	s.flatten(node1);
	
	TreeNode * root = node1;
	while(root != NULL){
		cout<<root->val<<" ";
		root = root->right;
	}
	cout<<endl;
}
