//
//decription:
//�ж��������Ƿ���ͬ
//
//solution��
//�ݹ���ߵ�������
 
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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if(p == NULL && q == NULL)
        	return true;
        if(p == NULL || q== NULL)
        	return false;
        if(p->val == q->val && isSameTree(p->left,q->left)
			&& isSameTree(p->right,q->right))
			return true;
		else
			return false;
    }
};


int main(){
	
}