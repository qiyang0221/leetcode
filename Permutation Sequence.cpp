//
//description:
//求n个字母组成的排列中第k的排列是？
//
//solution:
//用fac[i]代表有多少排列情况
//k/fac[i-1]等于多少就代表当前应该使用哪个数字
//逐个判断
 
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>

using namespace std;

class Solution {
public:
	int fac[10];
	bool vis[10];
    string getPermutation(int n, int k) {
    	string per;
    	string str = string("123456789").substr(0,n);
    	
    	fac[1] = 1;
    	fac[0] = 1;
    	for(int i=2;i<=n;i++)
    		fac[i] = fac[i-1] * i;
    		
    	for(int i=0;i<n;i++){
    		int index = (k-1) / fac[n-i-1];
    		per.push_back(str[index]);
    		str.erase(index,1);
    		k = k - index * fac[n-i-1];
    	}
    	
    	return per;
    }
};


int main(){
	Solution s;
	cout<<s.getPermutation(3,3)<<endl;
} 
