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
/*这道题目看的题解，采用有限状态自动机
/*0 初始或者只有空格的情况
/*1 输入数字或者只有数字 
/*2 输入点
/*3 输入符号+/-
/*4 既有点又有数字的情况1,2都可以变成4
/*5 第一次加入exp
/*6 exp后第一次遇到符号+/-
/*7 exp后有数字 5,6可以变成7
/*8 空格结尾
/*
/*所以可以得到如题的状态自动机
/*加入由java做的话可以列举可能的正则式，匹配即可，不过自动机的效率比较高，O(n)的复杂度 
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
