/*
/*question:
/*Validate if a given string is numeric.
/*Some examples:
/*"0" => true
/*" 0.1 " => true
/*"abc" => false
/*"1 a" => false
/*"2e10" => true
/*Note: It is intended for the problem statement to be ambiguous.
/*You should gather all requirements up front before implementing one.
/*
/*solution:
/*�����Ŀ������⣬��������״̬�Զ���
/*0 ��ʼ����ֻ�пո�����
/*1 �������ֻ���ֻ������ 
/*2 �����
/*3 �������+/-
/*4 ���е��������ֵ����1,2�����Ա��4
/*5 ��һ�μ���exp
/*6 exp���һ����������+/-
/*7 exp�������� 5,6���Ա��7
/*8 �ո��β
/*
/*���Կ��Եõ������״̬�Զ���
/*������java���Ļ������оٿ��ܵ�����ʽ��ƥ�伴�ɣ������Զ�����Ч�ʱȽϸߣ�O(n)�ĸ��Ӷ� 
*/ 
 

#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cstring>

using namespace std;

class Solution {
public:
	bool isdigit(char c){
		if(c >= '0'  && c <= '9')
			return true;
		else
			return false;
	}
	
    bool isNumber(const char *s) {
        enum INPUT_TYPE{INV,SPA,SIG,DIG,DOT,EXP};
        
        int fsm[][6] = {
        	-1,0,3,1,2,-1,
        	-1,8,-1,1,4,5,
        	-1,-1,-1,4,-1,-1,
        	-1,-1,-1,1,2,-1,
        	-1,8,-1,4,-1,5,
        	-1,-1,6,7,-1,-1,
        	-1,-1,-1,7,-1,-1,
        	-1,8,-1,7,-1,-1,
        	-1,8,-1,-1,-1,-1
		};
		
		int len = strlen(s);
		INPUT_TYPE input;
		int state = 0;
		for(int i=0;i<len;i++){
			if(s[i] == ' ') input = SPA;
			else if(s[i] == '+' || s[i] == '-') input = SIG;
			else if(isdigit(s[i])) input = DIG;
			else if(s[i] == '.') input = DOT;
			else if(s[i] == 'e' || s[i] == 'E') input = EXP;
			else
				input = INV;
			state = fsm[state][input];
			if(state == -1)
				return false;
		}
		
		if(state == 1 || state == 4 || state == 7 || state == 8)
			return true;
		return false;
    }
};

int main(){
	Solution s;
	if(s.isNumber(".1")){
		cout<<"true"<<endl;
	}else
		cout<<"false"<<endl;
}
