//
//description:
//�ж�һ�����Ƿ��ǻ�����
//
//solution:
//��������ķ��������Ƚ��Ƿ���ȣ���Ⱦ��ǻ�����
//���ܻ������������λ�ж� 
//�������ǻ�����
 
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstdio>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
        	return false;
        int tmp = x;
        int x_cp = 0;
        
        while(tmp){
        	x_cp = x_cp * 10 + tmp % 10;
        	tmp = tmp / 10;
        }
        
        if(x_cp == x)
        	return true;
        else
        	return false;
    }
};

int main(){
	
	Solution s;
	if(s.isPalindrome(12)){
		cout<<"true"<<endl; 
	}else
		cout<<"false"<<endl;
}
