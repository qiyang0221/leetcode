//
//description:
//爬楼，可以选择爬一步或者两步
//
//solution:
//f(n) = f(n-1) + f(n-2) ,斐波那契数数组
//更快的方法用公式

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
    	if(n == 0 || n == 1)
    		return 1;
    	vector<int> res;
    	res.push_back(1);
    	res.push_back(1);
    	for(int i=2;i<=n;i++){
    		int value = res[i-1] + res[i-2];
    		res.push_back(value);
    	}
    	
    	return res[n];
    }
};


int main(){
	Solution s;
	cout<<s.climbStairs(44)<<endl;
}
