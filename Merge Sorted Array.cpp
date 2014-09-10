#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int i = 0,j = 0,k = 0;
        int * C = new int [m+n];
        while(i < m && j < n){
        	if(A[i] < B[j]){
        		C[k++] = A[i++];
        	}else{
        		C[k++] = B[j++];
        	}
        }
        
        while(i < m){
        	C[k++] = A[i++];
        }
        while(j < n){
        	C[k++] = B[j++];
        }
        for(int l=0;l<k;l++){
        	A[l] = C[l];
        }
        for(int l=0;l<k;l++){
        	cout<<A[l]<<" ";
        }
        cout<<endl;
    }
};

int main(){
	int A[] = {1,3,4,4,6,10};
	int B[] = {1,2,2,4,5,6,9,11,12};
	Solution s;
	s.merge(A,6,B,9);
	
	return 0;
}
