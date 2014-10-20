//
//description:
//删除数组某个元素，返回数组大小
//
//solution:
//用Index指向元素应该放的前一个位置
//复杂度O(n)
 
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>

using namespace std;

class Solution {
public:
	int removeElement(int A[], int n, int elem) {
		int index = -1;
		for(int i=0;i<n;i++){
			if(A[i] != elem){
				A[++index] = A[i];
			}
		}
		
		return index+1;
	}
    /*int removeElement(int A[], int n, int elem) {
    	if(n == 0)
    		return 0;
    		
        sort(A,A+n);
        
        int left = 0,right = n-1;
        while(A[left] < elem && left < right){
        	int mid = left + (right - left) /2;
        	if(A[mid] < elem)
        		left = mid + 1;
        	else
        		left++;
        }
        
        while(A[right] > elem && right > left){
        	int mid = left + (right - left) /2;
        	if(A[mid] > elem)
        		right = mid - 1;
        	else
        		right--;
        }
        
        if(A[left] != elem || A[right] != elem)
        	return n;
        else{
        	for(int i=right+1,k=left;i<n;i++,k++){
        		A[k] = A[i];
        	}
        	
        	return n-right+left-1;
        }
        	
    }*/
};

int main(){
	int A[] = {0,3,1,1,0,1,3,0,3,3,1,1};
	Solution s;
	int len = s.removeElement(A,12,1);
	for(int i=0;i<len;i++)
		cout<<A[i]<<" ";
	cout<<endl;
}
