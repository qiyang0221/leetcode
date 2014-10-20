//
//description:
//��һ�����飬���Ƿ���Ե����յ� 
//
//solution:
//������ʵ��յ㣬���ܷ�һֱ����ֱ���յ�
//��һ��ֵ��¼��ǰ�ܵ������Զ����
//�����ǰi�����ϴ���Զ���룬����Ҫ����һ��
//ͬʱ��һ��ֵ��¼��ǰ��������Զ���� 

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;

class Solution {
public:
    bool canJump(int A[], int n) {
    	
    	if(n == 0 || n == 1)
        	return true;
        	
        int len = A[0];
		for(int i=1;i<n && i <= len;i++){
			len = len > (A[i] + i) ? len : (A[i]+i);
		}
		
		if(len >= n-1)
			return true;
		return false;
    }
};

int main(){
	int A[] = {2,5,0,0};
	
	Solution s;
	if(s.canJump(A,4)){
		cout<<"true"<<endl;
	}else{
		cout<<"false"<<endl;
	}
}
