//
//description:
//求目标值得上限和下限
//
//solution:
//二分求上限和下限
 
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
        while(A[left] != target && left < right){
			mid =  left + (right -left) / 2;
			if(A[mid] < target){
				left = mid + 1;
			}else{
				left++;
			}
        }
        
        while(left < right && A[right] != target){
        	mid = left + (right - left)/2;
        	if(A[mid] > target){
        		right = mid - 1;
        	}else{
        		right--;
        	}
        }
        
        vector<int> res;
        if(left <= right && A[left] == target){	
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
	
	vector<int> res = s.searchRange(A,9,0);
	cout<<res[0]<<" "<<res[1]<<endl;
}
