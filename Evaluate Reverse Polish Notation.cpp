//
//description:
//���沨��ʽ��� 
//
//solution��
//������Ŀһ��Ҫ����߽�case���ٽ���
//string�����Ƿ��ţ�Ҳ���������֣������ж�λ��ǰ�滹�������ţ�����Ҫ���� 
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<stack>
#include<vector>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> s;
        int fir,sec;
        for(int i=0;i<tokens.size();i++){
        	char op = tokens[i][0];
        	if(tokens[i].size() == 1 && ( op == '+' || op == '-' || op == '*' || op == '/') ){
        		fir = s.top();s.pop();
        		sec = s.top();s.pop();
        		if(tokens[i][0] == '+'){
        			s.push(fir+sec);
        		}else if(tokens[i][0] == '-'){
        			s.push(sec-fir);
        		}else if(tokens[i][0] == '/'){
        			s.push(sec/fir);
        		}else{
        			s.push(fir*sec);
        		}
        	}else{
        		int val = atoi(tokens[i].c_str());
        		s.push(val);
        	}
        }
        
        return s.top();
    }
};

int main(){
	vector<string> num;
	num.push_back("+10");
	num.push_back("1");
	num.push_back("*");
	num.push_back("-2");
	num.push_back("/");
	
	Solution s;
	cout<<s.evalRPN(num)<<endl;
}
