//
//description:
//��һ���ַ���S����һ���ַ���T
//��S���Դ��������ٸ�T
//����rabbbit����3��rabbit 
//
//solutions:
//�����Ŀ��򵥵�˼·����dfs�����������˴����� 
// Ȼ����ǿ���dp
//dp[i][j]��ʾS[0-i]���ж��ٸ�T[0-j]
//����dp[i][j] = dp[i-1][j] + (dp[i-1][j-1] && S[i] == T[j])
//���Կ���dp[i][j]������j��i��ʾ��һ�εĽ��
//����j���Դ�T.size()��ʼ
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
