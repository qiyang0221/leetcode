#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

class Solution {
public:
	int bSearch(int A[],int left,int right,int target){
		while(left <= right){
			int mid = (left + right) / 2;
			if(A[mid] == target)
				return mid;
			else if(target > A[mid])
				left = mid + 1;
			else 
				right = mid - 1;
		}
		
		return -1;
	}
    int search(int A[], int n, int target) {
    	int pivot = n-1;
    	if(n <= 0)
    		return -1;
    	if(A[0] > A[n-1]){
    		int l = 0,r = n-1;
    		while(l<=r){
    			int mid = (l+r)/2;
    			if((mid > 0 && A[mid] < A[mid-1])){
    				pivot = mid - 1;
    				break;
    			}
    			if((mid<n-1 && A[mid] > A[mid+1])){
					pivot = mid;
					break;	
				}
				if(A[mid] > A[l])
					l = mid + 1;
				if(A[mid] < A[r])
					r = mid - 1; 
    		}
    		
    	}
    	
    	if(target >= A[0]){
    		return bSearch(A,0,pivot,target);
    	}
    	
    	if(target <= A[n-1]){
    		return bSearch(A,pivot+1,n-1,target);
    	}
    	
    	return -1;
    }
};

int main(){
	int A[] = {3,1};
	
	Solution s;
	cout<<s.search(A,2,2)<<endl;
}
