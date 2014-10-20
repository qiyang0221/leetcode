//
//description:
//求一个字符串中最长回文字串 
//
//solution:
//这道题目最简单的思路就是dp,dp[i][j] = dp[i+1][j-1] && S[i] == S[j]，复杂度O(n^2) 
//还有一种思路是Mancher算法
//这里假设当前最长的回文数以id对称的，右边界是mx
//这里计算p[i]，i在p[j]的右边，i和j关于id对称
//如果p[j]<mx-i，那么p[i] = p[j] < mx-i
//如果p[j]>=mx-i,那么p[i]至少是mx-i
//所以p[i] = min(p[2*id-i],mx-i)，然后进行拓展
//如果新的i+p[i] > mx那么剩下的id = i,mx = i+p[i]
//这里分析一下复杂度， 
//while(str[i+p[i]] == str[i-p[i]]){p[i]++;}
//这一步的i+p[i]都是从mx进行扩展的，所以mx一直是递增的，而且mx的扩展是线性的,当mx=n就不再进行扩展
//并且剩下的字符串回文数最长也是mx-i
//所以复杂度是O(n) 

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>

using namespace std;

class Solution {
public:
    /*string longestPalindrome(string s) {
        int len = s.length();
        if(len <= 0)
        	return "";
        	
        bool dp[len][len];
        for(int i=0;i<len;i++)
        	dp[i][0] = true;
        int gap = 1;
        string res = s.substr(0,1);
        for(int gap=1;gap<len;gap++){
        	for(int i=0;i<len-gap;i++){
        		if(s[i] == s[i+gap] && ((i+1 > i+gap-1) || dp[i+1][gap-2])){
        			dp[i][gap] = true;
        			res = s.substr(i,gap+1);
        		}
        	}
        }
        
        return res;
    }*/
    
    string longestPalindrome(string s){
    	if(s.length() <= 1)
    		return s;
    		
    	string str = preProcess(s);
    	
    	int id = 0,mx = 0;
    	int len = str.length();
    	vector<int> p(len,0);
    	
    	for(int i=1;i<len-1;i++){
    		p[i] = mx > i ? min(p[2*id-i],mx-i) : 1;
    		
    		while(str[i+p[i]] == str[i-p[i]]){
    			p[i]++;
    		} 
    		
    		if(i+p[i] > mx){
    			mx = i+p[i];
    			id = i;
    		}
    	}
    	
    	int max = 0;
    	int index;
    	for(int i=1;i<len-1;i++){
    		if(p[i] > max){
    			max = p[i];
    			index = i;
    		}
    	}
    	
    	return s.substr((index-max)/2,max-1);
    }
    
    string preProcess(const string &s){
    	string res;
    	res.push_back('$');
    	res.push_back('#');
    	
    	for(int i=0;i<s.length();i++){
    		res.push_back(s[i]);
    		res.push_back('#');
    	}
    	
    	res.push_back('^');
    	
    	return res;
    }
};

int main(){
	Solution s;
	cout<<s.longestPalindrome("aaaaaaaaaaaaaaaaaaaaaaaa")<<endl;
}
