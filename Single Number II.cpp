//
//description:
//�������ֶ����������Σ���һ��������һ�Σ������
//
//solution:
//������32λ��ʾ�����һ�����ֳ�����3�Σ���ô��ģΪ0
//����ÿ�ν����ۼӣ���3����ģ������ĸ��Ӷ���O(n*32)
//
//�������Լ򻯳ɽ�������int�洢�Ϳ�����
//���� 5����������
//    fir sec thd 
// 1  101 000 000
// 2  000 101 000
// 3  101 000 101
//�����һ����������3�Σ���ôfir == thd
//���� sec |= fir & A[i] ������ֵ�һ�Σ���ôsec��Ӧ��λΪ0���ڶ��γ��֣���Ӧλ��Ϊ1��������Ҳ���� 
//     fir ^= fir     ��һ�ζ�Ӧ��λ�н�����ڶ���û�С��������� 
//     thd = fir & sec ���е����� sec��fir��Ӧ��λͬʱ����3�Σ���ʱ��Ӧ��λΪ0 
//     fir &= ~thd  ��Ӧȡ������ 
//     sec &= ~thd ��Ӧȡ������ 
//�������fir 
 
#include<cstdio>
#include<cstdlib>
#include<iostream>

using namespace std;

class Solution {
public:
    int singleNumber(int A[], int n) {
        int fir = 0,sec = 0,thd = 0;
        for(int i=0;i<n;i++){
        	sec |= fir & A[i];
        	fir ^= A[i];
        	
        	thd = fir & sec;
        	fir &= ~thd;
        	sec &= ~thd;
        }
        
        return fir;
    }
};

int main(){
	int A[] = {1,2,1,1,2,3,2};
	
	Solution s;
	cout<<s.singleNumber(A,7)<<endl;
}
