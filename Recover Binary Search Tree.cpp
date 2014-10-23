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

/*class Solution {
public:
    void recoverTree(TreeNode* root) {
        pair<TreeNode*, TreeNode*> broken;
        TreeNode* prev = NULL;
        TreeNode* cur = root;

        while (cur != NULL) {
            if (cur->left == NULL) {
                detect(broken, prev, cur);
                prev = cur;
                cur = cur->right;
            } else {
                TreeNode* node = cur->left;

                while (node->right != NULL && node->right != cur)
                    node = node->right;

                if (node->right == NULL) {
                    node->right = cur;
                    //prev = cur; ��������䣡��Ϊcur��û�б�����
                    cur = cur->left;
                } else {
                    detect(broken, prev, cur);
                    node->right = NULL;
                    prev = cur;
                    cur = cur->right;
                }
            }
        }

        swap(broken.first->val, broken.second->val);
    }

    void detect(pair<TreeNode*, TreeNode*>& broken, TreeNode* prev,
            TreeNode* current) {
        if (prev != NULL && prev->val > current->val) {
            if (broken.first == NULL) {
                broken.first = prev;
            } //������else������ {0,1}���ᵼ����� swapʱsecondΪNULL��
              //�� Runtime Error
            broken.second = current;
        }
    }
    
    void inorderTraverse(TreeNode * root){
    	if(root == NULL)
    		return;
    	inorderTraverse(root->left);
    	cout<<root->val<<" ";
    	inorderTraverse(root->right);
    }
};*/

int main(){
	Solution s;
	
	TreeNode * node1 = new TreeNode(4);
	TreeNode * node2 = new TreeNode(2);
	TreeNode * node3 = new TreeNode(5);
	TreeNode * node4 = new TreeNode(6);
	TreeNode * node5 = new TreeNode(4);
	TreeNode * node6 = new TreeNode(7);
	
	
	node1->left = node2;
	node2->right = node3;
	node1->right = node4;
	node4->left = node5;
	node4->right = node6;
	
	s.inorderTraverse(node1);
	cout<<endl;
	 
	s.recoverTree(node1);
	s.inorderTraverse(node1);
	cout<<endl;
}
