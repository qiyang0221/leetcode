#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;

const int MAX = 0x3f3f3f3f;

class Solution {
public:
	
    int jump(int A[], int n) {
        int last = 0,cur = 0;
        int hop = 0;
        for(int i=0;i<n;i++){
        	if(i>last){
        		last = cur;
        		hop++;
        	}
        	cur = cur > (A[i]+i) ? cur : (A[i]+i);
        }
        
        return hop;
    }
};

int main(){
	int A[] = {2,3,1,1,4};
	
	Solution s;
	int res = s.jump(A,5);
	printf("%d\n",res);
}
