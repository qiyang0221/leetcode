//
//description:
//正则式匹配，有两种.和*
//
//solution:
//如果s[i] == p[j] || p[j] == '.' dp[i][j] = dp[i-1][j-1]
//如果p[j] == '*'分为几种情况*可以表示0个，1个，多个
//if(dp[i][j-2] || (dp[i][j-1]) || (dp[i-1][j] &&(p[j-1] == '.' || p[j-2] == s[i-1]))) 
//时间复杂度O(m*n)空间O(m*n) 

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;


class Solution {
public:
	
	/*bool isMatch(const char *s, const char *p) {
		if(*p == '\0')
			return *s == '\0';
		if(*(p+1) != '*'){
			if(*s == *p || ( *p == '.' && *s != '\0')){
				if(isMatch(s+1,p+1))
					return true;
			}
			return false;
		}else{
			while(*s == *p || (*p == '.' && *s != '\0')){
				if(isMatch(s,p+2))
					return true;
				s++;
			}
			
			return isMatch(s,p+2);
		}
		
	}*/
	
    /*bool isMatch(const char *s, const char *p) {
        int slen = strlen(s);
        int plen = strlen(p);
        
        bool dp[slen+1][plen+1];
        memset(dp,0,sizeof(dp));
        
        dp[0][0] = true;
        for(int j=1;j<=plen;j++)
        	if(p[j-1] == '*') 
        		dp[0][j] = dp[0][j-2];
        for(int i=1;i<=slen;i++){
        	for(int j=1;j<=plen;j++){
        		if(p[j-1] == '.')
					dp[i][j] = dp[i-1][j-1];
				else if(p[j-1] == '*')
					dp[i][j] = dp[i][j-1] || dp[i][j-2] || (dp[i-1][j] && (s[i-1] == p[j-2] || p[j-2] == '.'));
				else
					dp[i][j] = dp[i-1][j-1] && s[i-1] == p[j-1]; 
        	}
        }
        
        return dp[slen][plen];
    }*/
};


int main(){
	
	Solution s;
	if(s.isMatch("aab",".*b.")){
		cout<<"true"<<endl;
	}else
		cout<<"false"<<endl;
}
