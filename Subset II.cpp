/*
/*question:
/*Given a collection of integers that might contain duplicates, S, return all possible subsets.
/*Note:
/*Elements in a subset must be in non-descending order.
/*The solution set must not contain duplicate subsets.
/*For example,
/*If S = [1,2,2], a solution is:
/*[
/*  [2],
/*  [1],
/*  [1,2,2],
/*  [2,2],
/*  [1,2],
/*  []
/*]
/*
/*solution:
/*由于集合中有重复的数字出现，所以这道题目重点是去重
/*例如：122445这种情况：1、首先遍历到前驱集合1224，然后剩下的调用dfs之后，
/*将第一个4删除之后，就不需要遍历第二个4了，因为第一个4已经前驱1224的情况考虑了，所以如果重复的字符不是第一个，就可以直接跳过
/*每次遍历一个字母之后，需要pop_up该字母
/*这道题目即使没有提到顺序也是需要排序的，排序方便去重
*/

//code: 

#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution{
	public:
		vector<vector<int> > subsetWithDup(vector<int> &S){
			sort(S.begin(),S.end());
			vector<int> path;
			vector<vector<int> > result;
			dfs(S,0,path,result);
			
			return result;
		}
		
		void dfs(vector<int> &S,int start,vector<int> &path,vector<vector<int> > &result){
			result.push_back(path);
			for(int i=start;i<S.size();i++){
				if(i != start && S[i] == S[i-1])
					continue;
				path.push_back(S[i]);
				dfs(S,i+1,path,result);
				path.pop_back();
			}
		}
		
		vector<vector<int> > subsetWithDup(vector<int> &S) {
	        sort(S.begin(),S.end());
	        vector<vector<int> > result(1);
	        
	        int presize = 0;
	        for(int i=0;i<S.size();i++){
	        	int size = result.size();
	        	for(int j=0;j<size;++j){
	        		if(i == 0 || S[i] != S[i-1] || j >= presize){
	        			result.push_back(result[j]);
	        			result.back().push_back(S[i]);
	        			pvector(result.back());
	        		}
	        	}
	        	presize = size;
	        }
	        
	        return result;
    	}
    	
};


//test:

int main(){
	vector<int> S;
	
	Solution s;
	vector<vector<int> > res = s.nonRur(S);
}
