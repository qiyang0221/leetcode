//
//description:
//ɾ�����������ظ���
//
//solution:
//ɾ�����������ظ��� 
//���������λ���������Ӷ���O(n^2)
//������һ��Indexָ����һ�����������ͬ��û��Ҫ�ƶ�����ͬ�ͷŵ�index+1
//���Ӷ�O(n)
 
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
