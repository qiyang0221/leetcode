//
//description：
//给一组collection的数据，求组合
//
//solution:
//这里除了排序，还需要考虑A[i] == A[i-1]的情况，这种情况下，就可以跳过
//避免重复出现 

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
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
			if(i != start && candidates[i] == candidates[i-1])continue;
    		line.push_back(candidates[i]);
    		find(res,candidates,line,i+1,left-candidates[i]);
    		line.pop_back();
    	}
    }
};

int main(){
	vector<int> candidates;
	candidates.push_back(10);
	candidates.push_back(1);
	candidates.push_back(2);
	candidates.push_back(7);
	candidates.push_back(6);
	candidates.push_back(1);
	candidates.push_back(5);
	
	Solution s;
	vector<vector<int> > res = s.combinationSum2(candidates,8);
	for(int i=0;i<res.size();i++){
		for(int j=0;j<res[i].size();j++)
			cout<<res[i][j]<<" ";
		cout<<endl;
	}
}
