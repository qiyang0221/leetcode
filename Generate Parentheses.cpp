//
//description:
//给定n求能产生多少不同的合法括号，同时记录所有
//
//solution:
//卡特兰数f(n)=f(0)f(n-1)+f(1)(n-2)+……+f(n-1)f(0)
//这里递归就好了，用一个left记录使用的左括号个数，用一个right记录右括号个数
//right始终小于等于left
//当left==size时，补齐剩下的right 


#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<stack>
#include<vector>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if(n <= 0)
        	return res;
        string line;
        recur(res,line,0,0,n);
        
        return res;
    }
    
    void recur(vector<string> &res,string line,int left,int right,int n){
    	line += "(";
    	if(left == n-1){
    		while(right <= left){
    			line+=")";
    			right++;
    		}
    		res.push_back(line);
    	}else{
    		left++;
    		for(int i=0;i<=left-right;i++){
    			string tmp(i,')');
    			recur(res,line+tmp,left,right+i,n);
    		}
    	}
    }
};

int main(){
	Solution s;
	vector<string> res = s.generateParenthesis(2);
	for(int i=0;i<res.size();i++)
		cout<<res[i]<<endl;
}
