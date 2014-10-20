//
//description:
//4sum,其他同3sum 
//
//solution:
//可以推广多k-sum,先进行k-2次循环，然后在剩下的数组进行夹逼
//复杂度O(n^(k-1)) 



#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > res;
        vector<int> line;
        sort(num.begin(),num.end());
        
        dfs(res,num,line,0,target,4);
        
        return res;
    }
    
    void dfs(vector<vector<int> > &res,vector<int> &num, vector<int> line,int start,int target,int cnt){
    	if(cnt == 2){
    		int j=start,k= num.size()-1;
    		while(j < k){
    			if(num[j] + num[k] == target){
    				vector<int> vec_cp(line);
    				vec_cp.push_back(num[j]);
    				vec_cp.push_back(num[k]);
    				res.push_back(vec_cp);
    				for(;num[j]==num[j+1];j++);
    				j++;
    			}else if(num[j] + num[k] > target){
    				k--;
    			}else
    				j++;
    		}
    	}else{
    		for(int i=start;i<num.size();i++){
    			if(i != start && num[i] == num[i-1])
    				continue;
    			line.push_back(num[i]);
    			dfs(res,num,line,i+1,target-num[i],cnt-1);
    			line.pop_back();
    		}
    	}
    }
};

int main(){
	vector<int> S;
	S.push_back(2);
	S.push_back(1);
	S.push_back(0);
	S.push_back(-1);
	/*S.push_back(-2);
	S.push_back(2);*/
	
	Solution solu;
	
	vector<vector<int> > res = solu.fourSum(S,2);
	for(int i=0;i<res.size();i++){
		for(int j=0;j<res[i].size();j++)
			cout<<res[i][j]<<" ";
		cout<<endl;
	}
}
