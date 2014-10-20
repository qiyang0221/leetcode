//
//description:
//给出一串括号，求最长合法括号子序列长度
//
//solution:
//这里刚开始陷入了误区，直接匹配扩，stack存的是括号
//其实应该stack存序号，这样才知道当前匹配了多少个字符串 


#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<stack>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int max = 0;
        int start = 0;
        for(int i=0;i<s.length();i++){
        	if(s[i] == '('){
        		st.push(i);	
        	}else{
        		if(st.empty()){
        			start = i+1;
        		}else{
        			st.pop();
        			if(st.empty()){
        				max = max > (i - start + 1) ? max : (i-start+1);
        			}else{
        				max = max > (i - st.top()) ? max : (i-st.top());
        			}
        		}
        	}
        }
        
        return max;
    }
};

int main(){
	string s("(()");
	
	Solution solu;
	
	cout<<solu.longestValidParentheses(s)<<endl;
}
