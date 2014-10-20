//
//description:
//��һ���ʵ䣬�ж��ַ����ܷ����ɴʵ�����Ĵ����
//
//solution:
//����һ��dp[i]��ʾi---n-1�����ֵ�����Ĵ��ﹹ��
//Ȼ���Ժ���ǰ�ж�str[i-j] && dp[j+1]�Ƿ����
 
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<set>

using namespace std;

class Solution {
public:
	
	bool wordBreak(string s, set<string> &dict) {
    	if(s.empty())
    		return true;
        int len = s.length();
        int dp[len+1];
        memset(dp,0,sizeof(dp));
        dp[0] = true;
        for(int i=1;i<=len;i++){
        	for(int j=i-1;j>=0;j--){
        		if(dp[j] && dict.count(s.substr(j,i-j)) > 0)
        			dp[i] = true;
        	}
        }
        
        return dp[len];
    }
    
	/*bool wordBreak(string s, set<string> &dict) {
    	if(s.empty())
    		return true;
    	int len = s.length();
    	bool dp[len][len+1];
    	memset(dp,0,sizeof(dp));
    	for(int i=0;i<len;i++)
    		if(dict.count(s.substr(i,1)) > 0)
    			dp[i][1] = true;
    	for(int j=2;j<=len;j++){
    		for(int i=0;i<=len-j;i++){
    			if(dict.count(s.substr(i,j)) > 0){
    				dp[i][j] = true;
    				continue;
    			}
    			for(int k=1;k<j;k++){
    				
    				if((dp[i][k] || dict.count(s.substr(i,k)) > 0)  && 
						(dp[i+k][j-k] || dict.count(s.substr(i+k,j-k)) > 0) ){
    					dp[i][j] = true;
    					break;
    				}
    			}
    		}
    	}
    	
    	
    	if(dp[0][len])
    		return true;
    	else
    		return false;
    }*/
    
    /*bool wordBreak(string s, set<string> &dict) {
    	if(s.empty())
    		return true;
        for(int len=1;len<=s.length();len++){
        	string str = s.substr(0,len);
        	if(dict.count(str) > 0){
        		if(wordBreak(s.substr(len),dict))
        			return true;
        	}
        }
        
        return false;
    }*/
};

int main(){
	Solution s;
	
	set<string> dict;
	dict.insert("leet");
	dict.insert("code");
	
	if(s.wordBreak("leetcde",dict))
		cout<<"true"<<endl;
	else
		cout<<"false"<<endl;
}
