//
//description:
//����Pow(x,n)
//
//solution:
//����nΪ�����͸��������
//�鲢��(x,n/2)�ӿ��ٶ�log(n) 

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>

using namespace std;

class Solution {
public:
    double pow(double x, int n) {
    	if(n == 0)
    		return 1;
    	if(n == 1)
    		return x;
    	double tmp = pow(x,abs(n/2));
    	if(n > 0){
    		if(n&1) return tmp * tmp * x;
    		else	return tmp * tmp;
    	}else{
    		if(n&1) return 1.0 / (tmp*tmp*x);
    		else
    			return 1.0/(tmp *tmp);
    	}
    }
};

int main(){
	Solution s;
	printf("%.5lf\n",s.pow(-0.99999,221620));
}
