//
//description:
//����������������ֵ�����ˣ���ָ�ԭ��
//
//solution:
//������ң��������˳���
//�����������Ҫ���ǣ�һ�־���ǰ�󽻻�
//һ���Ǹ��Ž�����
//������Ҫ����ֵ����¼������
//���A[i]>A[i+1]��A[i+1]�Ǵ����
//��һ��prev��¼��һ�����
 
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
