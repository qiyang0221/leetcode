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
	
	int removeDuplicates(int A[],int n){
		if(n <= 2)
			return n;
		int index = 1;
		for(int i=2;i<n;i++){
			if(A[index] != A[index-1]){
				A[++index] = A[i];
			}else{
				if(A[i] != A[index]){
					A[++index] = A[i];
				}
			}
		}
		
		return index+1;
	}
	
    /*int removeDuplicates(int A[], int n) {
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
    }*/
};

int main(){
	int A[] = {1,3,3,3};
	
	Solution s;
	int len = s.removeDuplicates(A,4);
	for(int i=0;i<len;i++){
		cout<<A[i]<<" ";
	}
	cout<<endl;
}
