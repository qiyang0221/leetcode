//
//description:
//最大字段和
//
//solution:
//见题 
#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;



class Solution {
public:
    int maxSubArray(int A[], int n) {
        int max = 0x80000001,sum = 0;
        
        for(int i=0;i<n;i++){
        	if(sum+A[i] > 0){
        		sum = sum + A[i];
        		if(sum > max)
        			max = sum;
        	}else{
        		sum = 0;
        		if(A[i] > max)
        			max = A[i];
        	}
        }
        
        return max;
    }
};

int main(){
	int A[] = {-2};
	
	Solution s;
	cout<<s.maxSubArray(A,1)<<endl;
}
