//
//description:
//求所有排列组合
//
//solution:
//dfs，加一个path记录路径，start记录当前位置 

#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	void swap(vector<int> &A,int a,int b){
		int tmp = A[a];
		A[a] = A[b];
		A[b] = tmp;
	}
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> >res;
        dfs(res,num,0);
        
        return res;
    }
    
    void dfs(vector<vector<int> > &res,vector<int> &num,int start){
    	if(start >= num.size()){
    		vector<int> num_cpy(num);
    		res.push_back(num_cpy);
    	}else{
    		for(int i=start;i<num.size();i++){
    			swap(num,i,start);
    			dfs(res,num,start+1);
    			swap(num,start,i);
    		}
    	}
    }
};

int main(){
	vector<int> num;
	num.push_back(1);num.push_back(2);num.push_back(3);
	
	Solution s;
	vector<vector<int> > res = s.permute(num);
	for(int i=0;i<res.size();i++){
		for(int j=0;j<res[i].size();j++){
			cout<<res[i][j];
		}
		cout<<endl;
	}
}
