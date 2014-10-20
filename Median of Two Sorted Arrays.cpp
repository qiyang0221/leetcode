//
//description:
//求两个有序数组的中位数
//中位数的定义是可以将一个数组对称分为两半
//前面的比当前数小，后面的比他大
//如果是偶数，就需要求i,i+1，中位数等于num[i]+num[i+1]
//这道题目可以转换为求第k大的数
//先求得pa = min(k/2,m)，如果pa<m，那么另一个数组求pb = k-pa
//如果A[pa] < B[pb] 那么说明A[pa]的数据肯定在前k个里面，还需要求k-pa得数
//剩下的数字可以再A(A+pa,m-pa,B,n,k-pa)里面求，反之亦然
 

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
