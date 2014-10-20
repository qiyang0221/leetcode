//
//description:
//�����������������λ��
//��λ���Ķ����ǿ��Խ�һ������ԳƷ�Ϊ����
//ǰ��ıȵ�ǰ��С������ı�����
//�����ż��������Ҫ��i,i+1����λ������num[i]+num[i+1]
//�����Ŀ����ת��Ϊ���k�����
//�����pa = min(k/2,m)�����pa<m����ô��һ��������pb = k-pa
//���A[pa] < B[pb] ��ô˵��A[pa]�����ݿ϶���ǰk�����棬����Ҫ��k-pa����
//ʣ�µ����ֿ�����A(A+pa,m-pa,B,n,k-pa)�����󣬷�֮��Ȼ
 

#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cmath>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
    	int media = (m+n);
    	if(media & 0x01){
    		return findKth(A,m,B,n,media/2+1);
    	}else{
    		return (findKth(A,m,B,n,media/2)+findKth(A,m,B,n,media/2+1))/2.0;
    	}
    }
    
    double findKth(int A[],int m,int B[],int n,int k){
    	if(m>n)
    		return findKth(B,n,A,m,k);
    	if(m==0)
    		return B[k-1];
    	if(k==1){
    		return min(A[0],B[0]);
    	}
    	int pa=min(k/2,m),pb = k-pa;
    	if(A[pa-1] > B[pb-1]){
    		return findKth(A,m,B+pb,n-pb,k-pb);
    	}else if(A[pa-1] < B[pb-1]){
    		return findKth(A+pa,m-pa,B,n,k-pa);
    	}else
    		return A[pa-1];
    }
};


int main(){
	int A[] = {1,2};
	int B[] = {1,2};
	
	Solution s;
	cout<<s.findMedianSortedArrays(A,,B,2)<<endl;
}
