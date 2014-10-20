//
//description:
//大整数乘法
//
//solution:
//大整数乘法
 
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        int len1 = num1.size();
        int len2 = num2.size();
        
        string res;
        if(len1<=0 || len2 <=0)
        	return res;
        
        int a[len1];
        for(int i=len1-1;i>=0;i--){
        	a[len1-i-1] = num1[i] - '0';
        }
        
        int b[len2];
        for(int i=len2-1;i>=0;i--){
        	b[len2-i-1] = num2[i] - '0';
        }
        
        int c[len1+len2];
        
        memset(c,0,sizeof(c));
        
        int carry;
        int i,j;
        for(i=0;i<len1;i++){
        	carry = 0;
        	for(j=0;j<len2;j++){
        		c[i+j] = c[i+j] + a[i] * b[j] + carry;
        		carry = c[i+j] / 10;
        		c[i+j] = c[i+j] % 10;
        	}
        	c[i+j] = carry;
        }
        c[len1+len2-1] = carry;
        
        int len3 = len1+len2;
        while(len3 > 1 && c[len3-1] == 0 ) len3--;
        
        for(int i=len3-1;i>=0;i--){
        	res.push_back(c[i]+'0');
        }
        
        return res;
    }
};

int main(){
	string a="98";
	string b="9";
	
	Solution s;
	cout<<s.multiply(a,b)<<endl;;
}
