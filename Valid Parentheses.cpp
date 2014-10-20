//
//description:
//�ж������Ƿ�Ϸ�
//
//solution:
//stack�ж�stack.top()�뵱ǰ�Ƿ���� 
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int i = 0;
        for(i=0;i,s.length();i++){
        	if(s[i] == '(' || s[i] == '{' || s[i] ==  '[')
        		st.push(s[i]);
        	else{
        		if(st.empty())
        			break;
        		else if((s[i] == ')' && st.top() == '(') ||
						(s[i] == ']' && st.top() == '[') ||
						(s[i] == '}' && st.top() == '{')){
					st.pop();		
				}else{
					break;
				}
        	}
        }
        
        if(i == s.length() && st.empty())
        	return true;
        else
        	return false;
    }
};


int main(){
	string str("(){}");
	
	Solution s;
	if(s.isValid(str))
		cout<<"true"<<endl;
	else
		cout<<"false"<<endl;
}
