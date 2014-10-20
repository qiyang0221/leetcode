//
//description:
//删除有序数的重复数
//
//solution:
//删除有序数组重复数 
//如果采用移位操作，复杂度是O(n^2)
//但是用一个Index指向上一个数，如果相同就没必要移动，不同就放到index+1
//复杂度O(n)
 
#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

class Solution {
public:
    /*int removeDuplicates(int A[], int n) {
        if(n <= 0)
        	return 0;
        int i = 0,start = 0,end;
        while(start < n){
        	for(end = start;A[start] == A[end] && end < n;end++);       		
        	A[i] = A[start];
        	start = end;
        	i++;
        }
        
        return i;
    }*/
    
    int removeDuplicates(int A[], int n){
    	if(n<=1)
    		return n;
    	int index = 0;
    	for(int i=1;i<n;i++){
    		if(A[index] != A[i]){
    			A[++index] = A[i];
    		}
    	}
    	
    	return index+1;
    }
};

int main(){
	int A[] = {1,2,2,3};
	Solution s;
	int len = s.removeDuplicates(A,4);
	for(int i=0;i<len;i++){
		cout<<A[i]<<" ";
	}
	cout<<endl;
}
