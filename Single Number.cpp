//
//description:
//��һ������ÿ�����������ߣ�����һ��������һ��
//��ø���
//
//solution:
//���н���ֻ򣬾������ս�����ֻ����㽻���ɺͽ���� 
 
#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

class Solution {
public:
    int singleNumber(int A[], int n) {
        int res = A[0];
        for(int i=1;i<n;i++)
        	res = res ^ A[i];
        return res;
    }
};

int main(){
	Solution s;
	int A[] = {1};
	cout<<s.singleNumber(A,1)<<endl;
}
