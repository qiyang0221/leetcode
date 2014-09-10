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
/*���ڼ��������ظ������ֳ��֣����������Ŀ�ص���ȥ��
/*���磺122445���������1�����ȱ�����ǰ������1224��Ȼ��ʣ�µĵ���dfs֮��
/*����һ��4ɾ��֮�󣬾Ͳ���Ҫ�����ڶ���4�ˣ���Ϊ��һ��4�Ѿ�ǰ��1224����������ˣ���������ظ����ַ����ǵ�һ�����Ϳ���ֱ������
/*ÿ�α���һ����ĸ֮����Ҫpop_up����ĸ
/*�����Ŀ��ʹû���ᵽ˳��Ҳ����Ҫ����ģ����򷽱�ȥ��
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
