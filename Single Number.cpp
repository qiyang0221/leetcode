//
//description:
//有一组数，每个出现了两边，仅有一个出现了一次
//求该该数
//
//solution:
//所有结果抑或，就是最终结果，抑或满足交换律和结合律 
 
#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

class Solution {
public:
    int singleNumber(int A[], int n) {
        int res = A[0];
        for(int i=1;i<n;i++)
        	res = res ^ A[i];
        return res;
    }
};

int main(){
	Solution s;
	int A[] = {1};
	cout<<s.singleNumber(A,1)<<endl;
}
