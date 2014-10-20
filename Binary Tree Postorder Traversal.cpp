//
//description:
//ʹ��O(n)ʱ�䣬O(1)�ռ�������
//
//solution:
//����Ҳ����morris������
//���Ǻ���Ƚ���֣���ǰ�ڵ����Һ��ӵ��������Һ���Ϊ�յĽڵ�֮�����
//������������ǰ������һ���ڵ�����ӵ����ҽڵ�
//��ô���뵽���������Ǿ���Ҫ�ع�ͷ���ʸ��ڵ㣬�ռ�϶���O(1)��
//���������������һ���µĸ��ڵ㣬������ڵ��������ָ��ԭ���ĸ��ڵ�
//�������򣬵�ǰ�ڵ㣬��������ڵ㣬�Ǻ���ĵ���,��ӡ��ʱ����Ҫ����˳�� 
 
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
