/*
/*question:
/*Given a set of distinct integers, S, return all possible subsets.
/*
/*solution:
/*有两种方法，迭代和非迭代
/*由于这里的数都是不同的，所以子集肯定不同
/*复杂情况参加subset II
*/

//code: 
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int> > result(1);
        
    	sort(S.begin(),S.end());
    	
        for(int c=0;c<S.size();c++){
        	int res_size = result.size();
        	for(int s=0;s<res_size;s++){
        		result.push_back(result[s]);
        		result.back().push_back(S[c]);
        	}
        }
        
        return result;
    }
};

int main(){
	vector<int> S;
	S.push_back(1);
	S.push_back(3);
	S.push_back(2);
	
	Solution solu;
	vector<vector<int> > result = solu.subsets(S);
	
	for(int i=0;i<result.size();i++){
		for(int j=0;j<result[i].size();j++)
			cout<<result[i][j]<<" ";
		cout<<endl;
	}
}
