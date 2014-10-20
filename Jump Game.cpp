//
//description:
//给一个数组，问是否可以到达终点 
//
//solution:
//逐个访问到终点，看能否一直覆盖直到终点 

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;

class Solution {
public:
    bool canJump(int A[], int n) {
    	
    	if(n == 0 || n == 1)
        	return true;
        	
        int len = A[0];
		for(int i=1;i<n && i <= len;i++){
			len = len > (A[i] + i) ? len : (A[i]+i);
		}
		
		if(len >= n-1)
			return true;
		return false;
    }
};

int main(){
	int A[] = {2,5,0,0};
	
	Solution s;
	if(s.canJump(A,4)){
		cout<<"true"<<endl;
	}else{
		cout<<"false"<<endl;
	}
}
