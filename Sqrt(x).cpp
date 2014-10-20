//
//description:
//求sqrt(x)
//
//solution:
//二分的思想
//left = 0,right = x;
//这里求整数，所以mid = (left+right)/2
//mid2 = x / mid;
//如果mid == mid2就得到结果否则继续迭代
//复杂度O(log(n))
 
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>

using namespace std;


class Solution {
public:
    int sqrt(int x) {
    	
    	if(x == 0)
    		return 0;
    	if(x == 1)
    		return 1;
    	int left = 0, right = x;
    	
    	while(left < right){
    		int mid = left + (right - left) / 2;
    		int mid2 = x / mid;
    		if(mid2 == mid)
    			return mid;
    		else if(mid2 > mid){
    			left = mid + 1;
    		}else{
    			right = mid - 1;
    		}
    	}
    	
    	if(left * left > x)
    		left = left - 1;
    	return left;
    }
};


int main(){
	Solution s;
	cout<<s.sqrt(4)<<endl;
}
