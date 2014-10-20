//
//description:
//转换一个整数
//
//solution:
//不需要担心溢出，也不需要但是负数 
#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

typedef long long ll;

class Solution {
public:
    int reverse(int x) {
    	int res = 0;
    	for(;x;x/=10)
    		res = res * 10 + x%10;
    	return res;
    	/*bool flag = true;
        if(x < 0)
        	flag = false;
        ll tmp = abs(x);
        ll res = 0;
        while(tmp){
        	res = res * 10 + tmp %10;
        	tmp = tmp / 10;
        }
        
        if(!flag)
        	return -res;
        else
        	return res;*/
    }
};

int main(){
	Solution s;
	
	cout<<s.reverse(-123)<<endl; 
}
