//
//description:
//求最大字段积
//
//solution:
//借鉴最大字段和的思路，用一个变量存max_pos
//又因为存在负数，所以最大数可能因为max_neg * cur获得
//然后遍历一遍O(n)复杂度 
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
