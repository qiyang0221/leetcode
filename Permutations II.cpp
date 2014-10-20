//
//description:
//��һ��������ȫ���У����ֿ������ظ�
//
//solution��
//��sortһ������
//Ȼ�������������
//vis[i]��ʾ��һ����ĸ
//first��ʾ��ǰ�ĵ�һ����ĸ
//s[i] == s[i-1]���ظ���
 
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
public:
	
    vector<vector<int> > permuteUnique(vector<int> &num) {
    	sort(num.begin(),num.end());
    	
    	vector<vector<int> > res;
    	vector<int> vis(num.size(),0);
    	vector<int> tmp_res;
    	
        dfs(res,num,vis,tmp_res,0);
        
        return res;
    }
    
    void dfs(vector<vector<int> > &res,vector<int> &num,vector<int> &vis,vector<int> tmp_res,int depth){
    	if(depth >= num.size()){
    		vector<int> tmp(tmp_res);
    		res.push_back(tmp);
    		return;
    	}
    	int first = 0,last;
    	for(int i=0;i<num.size();i++){
    		if(!vis[i]){
    			if(first ==0 || num[i] != last){
    				tmp_res.push_back(num[i]);
    				vis[i] = true;
    				dfs(res,num,vis,tmp_res,depth+1);
    				vis[i] = false;
    				tmp_res.pop_back();
    				first = 1;
    				last = num[i];
    			}
    		}
    	}
    }
};

int main(){
	vector<int> num;
	num.push_back(1);
	num.push_back(1);
	num.push_back(2);
	num.push_back(3);
	num.push_back(3);
	
	Solution s;
	vector<vector<int> >res = s.permuteUnique(num);
	for(int i=0;i<res.size();i++){
		for(int j=0;j<res[i].size();j++){
			cout<<res[i][j]<<" ";
		}
		cout<<endl;
	}
}
