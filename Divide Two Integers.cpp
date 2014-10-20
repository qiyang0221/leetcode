//
//description:
//��a/b��ֵ,�����ó˷��ͳ���
//
//solution:
//��Ҫע�⣬ab����Ϊ��,��ֵ����ֵ����ֵ��1
//ʹ��longlong��ֹ���
//���a<b return0
//bb = b;
//����bb<<=1;��¼��λ�Ĵ���
//�ҵ�bb>a��ʱ��Ȼ��ʼ������ֱ��a<b���ǽ�� ��a�ǳ�ʼֵ 

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
