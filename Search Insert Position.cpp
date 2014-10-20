//
//description:
//查找原数应该插入的位置
//
//solution:
//二分查找
 
#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int left = 0,right = n-1;
        while(left < right){
        	int mid = left + (right - left)/2;
        	if(target == A[mid])
        		return mid;
        	else if(A[mid] < target){
        		left = mid + 1;
        	}else
        		right = mid - 1;
        }
        
        if(A[left] < target)
        	left = left + 1;
        
        return left;
    }
};

int main(){
	int A[] = {1,3,5,6};
	
	Solution s;
	cout<<s.searchInsert(A,4,0)<<endl;
}
