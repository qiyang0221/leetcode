//
//description:
//�����������Ҫ��O(1)�ռ䣬O(n)ʱ��
//
//solution:
//�����õ�����morris������������
//�����ǰ��������Ϊ�գ���ô������������
//�����Ϊ�գ����ҵ���ǰ������������Ҷ�ڵ㣬����ǰ�ڵ�ǰ��
//��������������Ҷ�ڵ��rchild���ӵ���ǰ�ڵ�
//Ȼ���������������
//���һ���ڵ����ǰ��ʱָ�����Լ���˵��ǰ���Ѿ�������ˣ���ǰ��ָ���Լ���ָ������ΪNULL
//ͬʱ����������
//
//�������һ��O(n)ʱ��:
//����ǰ���Ĺ��̣���ʵ���൱�ڷ�������������Ȼ����ݸ���ǰ�����ʵ��Լ���ʱ���ٲ�����һ��ǰ����
//�����ܹ��������������Σ���ʱ��Ϊ2n,���Ӷ�ΪO(n) 

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
