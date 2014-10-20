#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        int left = 0,right = n-1;
        int mid;
        while(left < right){
			mid =  left + (right -left) / 2;
			if(A[mid] == target){
				break;
			}else if(A[mid] < target){
				left = mid + 1;
			}else{
				right = mid - 1;
			}  	
        }
        mid = left + (right - left) / 2;
        
        while(left < mid){
        	int mm = left + (mid-left)/2;
        	if(A[mm] == target){
        		for(;A[left] < target;left++);
        		break;
        	}
        		
        	else
        		left = mm+1;
        }
        
        while(right > mid){
        	int mm = mid + (right-mid)/2;
        	if(A[mm] == target){
        		if(A[right] > target)
        		for(;A[right] > target;right--);
        		break;
        	}
        		
        	else
        		right = mm - 1;
        }
        
        vector<int> res;
        if(A[mid] == target){	
	        res.push_back(left);
	        res.push_back(right);
        }else{
        	res.push_back(-1);
        	res.push_back(-1);
        }
        
        
        return res;
    }
};

int main(){
	int A[] = {1,2,3,3,3,3,4,5,9};
	
	Solution s;
	
	vector<int> res = s.searchRange(A,9,3);
	cout<<res[0]<<" "<<res[1]<<endl;
}
