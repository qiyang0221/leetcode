#include<cstdio>
#include<cstdlib>
#include<iostream>

using namespace std;
class Solution {
public:
	void move(int A[],int index,int n){
		for(int i=index;i<n-1;i++)
			A[i] = A[i+1];
	}
	
    int removeDuplicates(int A[], int n) {
        if(n <= 2)
        	return n;
        int pre = 0, cur = 1,next = 2;
        while(next < n){
        	if(A[pre] == A[next]){
        		move(A,next,n);
        		n--;
        	}else{
        		pre = cur;
        		cur = next;
        		next++;
        	}
        }
        
        return n;
    }
};

int main(){
	int A[] = {1,1,1,2,5,5,5};
	
	Solution s;
	int len = s.removeDuplicates(A,7);
	for(int i=0;i<len;i++){
		cout<<A[i]<<" ";
	}
	cout<<endl;
}
