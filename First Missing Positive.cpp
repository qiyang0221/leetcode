//
//description：
//查找第一个不存在的正整数
//
//solution:
//迭代将每一个整数归位
//比如[3,4,-1,1]
//->[-1,4,3,1]
//->[-1,1,3,4]->[1,-1,3,4]
//然后查找第一个跟本身不相等的数字即可 

#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

class Solution {
public:
    int firstMissingPositive(int A[], int n) {
    	if(n<=0)
    		return 1;
        for(int i=0;i<n;i++){
        	if(A[i] != i+1){
        		int tmp = A[i];
        		while( tmp >0 && tmp <=n && tmp != A[tmp-1]){
        			int tt = A[tmp-1];
        			A[tmp-1] = tmp;
        			tmp = tt;
        		}
        	}
        }
        
        for(int i=0;i<n;i++)
        	if(A[i] != i+1)
        		return i+1;
        return n+1;
    }
};

int main(){
	Solution s;
	
	int A[] = {3,4,-1,1};
	cout<<s.firstMissingPositive(A,4)<<endl;
}
