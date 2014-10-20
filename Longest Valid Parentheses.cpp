//
//description:
//����һ�����ţ�����Ϸ����������г���
//
//solution:
//����տ�ʼ������������ֱ��ƥ������stack���������
//��ʵӦ��stack����ţ�������֪����ǰƥ���˶��ٸ��ַ��� 


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
