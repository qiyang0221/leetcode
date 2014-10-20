//
//description:
//给一个字符串S和另一个字符串T
//求S的自传包含多少个T
//比如rabbbit包含3个rabbit 
//
//solutions:
//这道题目最简单的思路就是dfs，不过过不了大数据 
// 然后就是考虑dp
//dp[i][j]表示S[0-i]中有多少个T[0-j]
//这样dp[i][j] = dp[i-1][j] + (dp[i-1][j-1] && S[i] == T[j])
//可以看到dp[i][j]仅依赖j，i表示上一次的结果
//所有j可以从T.size()开始
//dp[j] = dp[j] + dp[j-1]
 
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<map>
#include<vector>
#include<cstring>

using namespace std;

class Solution {
public:
	int res;
    int numDistinct(string S, string T) {
        
        int s_size = S.size();
        int t_size = T.size();
        
        int dp[t_size+1];
        memset(dp,0,sizeof(dp));
        dp[0] = 1;
        
        for(int i=0;i<s_size;++i){
        	for(int j=t_size-1;j>=0;--j){
        		if(S[i] == T[j]){
        			dp[j+1] += dp[j];
        		}
        	}
        }
        
        return dp[t_size];
        
    }
};

int main(){
	Solution s;
	cout<<s.numDistinct("rabbbit","rabbit")<<endl;
}
