/*
/*question:
/*Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
/*For example,
/*If n = 4 and k = 2, a solution is:
/*
/*[
/*  [2,4],
/*  [3,4],
/*  [2,3],
/*  [1,2],
/*  [1,3],
/*  [1,4],
/*]
/*
/*solution:
/*求排列组合，自然的想法就是c(n,k)，以k作为递归的次数
/*为了避免重复，每次从上次的结果的最后一个数字的下一位开始
*/

//code:
 
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
	
	vector<vector<int> > dfs(int n,int k,int depth,vector<vector<int> > &input){
		if(depth >= k)
			return input;
		vector<vector<int> > result;
		for(int i=0;i<input.size();i++){
			int start = input[i][depth-1];
			for(int j=start+1;j+k-depth-1<=n;j++){
				result.push_back(input[i]);
				result.back().push_back(j);
			}
		}
				
		return dfs(n,k,depth+1,result);
	}
	
    vector<vector<int> > combine(int n, int k) {
    	vector<vector<int> > input;
    	if(n == 0 || k == 0)
    		return input;
    	for(int i=1;i+k-1<=n;i++){
    		vector<int> v_tmp;
    		v_tmp.push_back(i);
    		input.push_back(v_tmp);
    	}
    	
    	return dfs(n,k,1,input);
    }
};

int main(){
	Solution s;
	vector<vector<int> > result = s.combine(4,4);
	for(int i=0;i<result.size();i++){
		for(int j=0;j<result[i].size();j++){
			cout<<result[i][j]<<" ";
		}
		cout<<endl;
	}
}
