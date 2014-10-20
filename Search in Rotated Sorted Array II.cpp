//
//description:
//在一个旋转的有序数组查找目标数
//
//solution:
//有序数组可以重复，采用二分法
//这里有几种情况需要考虑
//if A[l] < A[mid]
//		if target >= A[l] && target < A[mid] then r = mid;
//		else target <A[l]或者target > A[mid] then l = mid-1;
//else if(A[l] > A[mid])
//		if target <= A[r] && target > A[mid] the l = mid+1
//		else r = mid;
//else l++;
		 
 
#include<cstdio>
#include<cstdlib>
#include<iostream>

using namespace std;

class Solution {
public:
    bool search(int A[], int n, int target) {
        if(n <= 0)
        	return false;
        int l=0,r=n;
        if(target < A[0] && target > A[n-1])
        	return false;
        	
        while(l<r){
        	int mid = (l+r) / 2;
        	if(A[mid] == target)
        		return true;
        	if(A[l] < A[mid]){
        		if(A[l] <= target && target < A[mid])
        			r = mid;
        		else
        			l = mid+1;
        	}else if(A[l] > A[mid]){
        		if(target > A[mid] && target <= A[r-1])
        			l = mid+1;
        		else
        			r = mid;
        	}else
        		l++;
        }
        
        return false;
    }
};


int main(){
	int A[] = {1};
	
	Solution s;
	if(s.search(A,1,0))
		cout<<"true"<<endl;
	else
		cout<<"false"<<endl;
		
	return 0;
}
