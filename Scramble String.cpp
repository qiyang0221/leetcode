/*
/*question:
/*https://oj.leetcode.com/problems/scramble-string/
/*
/*solution:
/*
/*�ݹ鱩��ö�٣� 
/*�����Ŀ��򵥵ķ������Ǳ����ݹ����k��(0��len)���ַ����и�����Σ�Ȼ��һһ�ж���Ӧ���ȵ������ܷ�ƥ��
/*�����ݹ�Ҫ���Ļ�������м�֦�����Ƚ��г����ж���Ȼ���ַ��������ж������ַ����Ƿ��Ƿ����
/*
/*��̬�滮��
/*���ﶨ�����ζ�̬�滮dp[k][i][j],k������,i,j������ʼ��
/*��̬�滮����:
/*            dp[k][i][j] = {(dp[m][i][j] && dp[k-m][i+m][j+m]) || (dp[m][i][j+k-m] && dp[k-m][i+m][j])} m��(1,k) 
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
