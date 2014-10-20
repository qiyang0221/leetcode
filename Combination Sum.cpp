//
//description:
//����һ�����ļ��ϣ������������target��������ϣ��������ظ�ѡȡ
//
//solution��
//�����Ǽ��ϣ����Բ��ÿ����ظ�������
//�����򣬰�С��ȡ�꣬��ȡ���
//����������ϵ����⣬Ϊ��ȥ�ض���Ҫ����������
//���Ӷ�O(n��) 


#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(),candidates.end());
        
        vector<vector<int> > res;
        vector<int> line;
        find(res,candidates,line,0,target);
        
        return res;
    }
    
    void find(vector<vector<int> > &res,vector<int> &candidates, vector<int> &line,int start,int left){
    	if(left == 0){
    		vector<int> tmp(line);
    		res.push_back(tmp);
    		return;
    	}
		for(int i=start;i<candidates.size() && candidates[i] <= left;i++){
    		line.push_back(candidates[i]);
    		find(res,candidates,line,i,left-candidates[i]);
    		line.pop_back();
    	}
    }
};

int main(){
	vector<int> candidates;
	candidates.push_back(2);
	candidates.push_back(3);
	candidates.push_back(6);
	candidates.push_back(7);
	
	Solution s;
	vector<vector<int> > res = s.combinationSum(candidates,7);
	for(int i=0;i<res.size();i++){
		for(int j=0;j<res[i].size();j++)
			cout<<res[i][j]<<" ";
		cout<<endl;
	}
}
