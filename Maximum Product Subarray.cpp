//
//description:
//������ֶλ�
//
//solution:
//�������ֶκ͵�˼·����һ��������max_pos
//����Ϊ���ڸ��������������������Ϊmax_neg * cur���
//Ȼ�����һ��O(n)���Ӷ� 
#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

class Solution {
public:
	int max(int a,int b){
		return a>b?a:b;		
	}
	
	int min(int a,int b){
		return a<b?a:b;
	}
	
    int maxProduct(int A[], int n) {
    		
        int glo = A[0];
        int max_local = A[0],min_local = A[0];
        
        for(int i=1;i<n;i++){
        	int max_cp = max_local;
        	
        	max_local = max(max(max_local*A[i],A[i]),min_local*A[i]);
        	min_local = min(min(max_cp*A[i],A[i]),min_local*A[i]);
        	
        	glo = max(glo,max_local);
        }
        
        return glo;
    }
};

int main(){
	Solution s;
	
	int A[] = {2,-2,4,-3,7,-2};
	
	cout<<s.maxProduct(A,6)<<endl;
}
