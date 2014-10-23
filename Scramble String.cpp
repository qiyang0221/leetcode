/*
/*question:
/*https://oj.leetcode.com/problems/scramble-string/
/*
/*solution:
/*
/*递归暴力枚举： 
/*这道题目最简单的方法就是暴力递归对于k∈(0，len)将字符串切割成两段，然后一一判定相应长度的两段能否匹配
/*暴力递归要过的话必须进行减枝，首先进行长度判定，然后将字符串排序，判断所有字符串是否是否相等
/*
/*动态规划：
/*这里定义三次动态规划dp[k][i][j],k代表长度,i,j代表起始点
/*动态规划方程:
/*            dp[k][i][j] = {(dp[m][i][j] && dp[k-m][i+m][j+m]) || (dp[m][i][j+k-m] && dp[k-m][i+m][j])} m∈(1,k) 
*/





#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
    	if(s1.length() != s2.length())
    		return false;
    	int len = s1.length();
    	bool dp[len+1][len][len];
    	memset(dp,0,sizeof(dp));
    	for(int i=0;i<len;i++)
    		for(int j=0;j<len;j++)
    			if(s1[i] == s2[j])
    				dp[1][i][j] = true;
    	for(int k=2;k<=len;k++){
    		for(int i=0;i+k<=len;i++){
    			for(int j=0;j+k<=len;j++){
    				for(int m=1;m<=k;m++){
    					if(dp[m][i][j] && dp[k-m][i+m][j+m])
    						dp[k][i][j] = true;
    					if(dp[m][i][j+k-m] && dp[k-m][i+m][j])
    						dp[k][i][j] = true;
    				}
    			}
    		}
    	}
    	
    	if(dp[len][0][0])
    		return true;
    	else
    		return false;
    }
};

int main(){
	Solution s;
	if(s.isScramble("abcd","bdac")){
		cout<<"true"<<endl;
	}else{
		cout<<"false"<<endl;
	}
}
