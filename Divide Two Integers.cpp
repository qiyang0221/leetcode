//
//description:
//求a/b的值,不能用乘法和除法
//
//solution:
//需要注意，ab可能为负,负值绝对值比正值大1
//使用longlong防止溢出
//如果a<b return0
//bb = b;
//否则bb<<=1;记录移位的次数
//找到bb>a的时候，然后开始计数，直到a<b就是结果 ，a是初始值 

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>

using namespace std;

typedef long long ll;
class Solution {
public:
    int divide(int dividend, int divisor) {
        
		ll a = abs((ll)dividend);
		ll b = abs((ll)divisor);
		
		ll i = 1;
		while(b < a){
			b<<=1;
			i<<=1;
		}
		
		if(b > a){
			b>>=1;
			i>>=1;
		}
		
		
		ll res = 0;
		while(a >= b  && a > 0){
			a -= b;
			res += i;
			while( a < b){
				b >>= 1;
				i >>= 1;
			}	
		}
		
		return (dividend < 0) ^ (divisor < 0) ? -res : res;
    }
};


int main(){
	Solution s;
	
	cout<<s.divide(2147483647,3)<<endl;
}
