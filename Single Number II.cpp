//
//description:
//所有数字都出现了三次，仅一个出现了一次，求该数
//
//solution:
//数字又32位表示，如果一个数字出现了3次，那么求模为0
//所以每次进行累加，到3就求模，这里的复杂度是O(n*32)
//
//不过可以简化成仅用三个int存储就可以了
//假设 5出现了三次
//    fir sec thd 
// 1  101 000 000
// 2  000 101 000
// 3  101 000 101
//既如果一个数出现了3次，那么fir == thd
//所以 sec |= fir & A[i] 如果出现第一次，那么sec相应的位为0，第二次出现，相应位就为1，第三次也出现 
//     fir ^= fir     第一次对应的位有结果、第二次没有、第三次有 
//     thd = fir & sec 仅有第三次 sec和fir对应的位同时出现3次，此时对应的位为0 
//     fir &= ~thd  相应取反即可 
//     sec &= ~thd 相应取反即可 
//结果就是fir 
 
#include<cstdio>
#include<cstdlib>
#include<iostream>

using namespace std;

class Solution {
public:
    int singleNumber(int A[], int n) {
        int fir = 0,sec = 0,thd = 0;
        for(int i=0;i<n;i++){
        	sec |= fir & A[i];
        	fir ^= A[i];
        	
        	thd = fir & sec;
        	fir &= ~thd;
        	sec &= ~thd;
        }
        
        return fir;
    }
};

int main(){
	int A[] = {1,2,1,1,2,3,2};
	
	Solution s;
	cout<<s.singleNumber(A,7)<<endl;
}
