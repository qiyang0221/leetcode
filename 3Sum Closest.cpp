/*
//title:3Sum Closest

//description:
//Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target.
//Return the sum of the three integers. You may assume that each input would have exactly one solution.
//For example, given array S = {-1 2 1 -4}, and target = 1.
//The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
//
//soltuion:
//首先将数组进行排序
//然后数组头部选择一个数，用tmp = target-A[i]，再从剩下的数组里面夹逼，找到上面结果相等的情况
//复杂度为O(n^2) 
//
*/

#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
    	int closet = 0x3f3f3f3f;
    	sort(num.begin(),num.end());
    	
        for(int i=0;i<num.size();i++){
        	if(i != 0 && num[i] == num[i-1])
        		continue;
        	int l = i+1,r = num.size()-1;
        	int tmp = target - num[i];
        	while(l < r){
        		if(num[l] + num[r] == tmp)
        			return target;
        		int diff = num[l] + num[r] - tmp;
        		if(abs(diff) < abs(closet)){
        			closet = diff;
        		}
        		
        		if(num[l] + num[r] > tmp)
        			r--;
        		else
        			l++;
        	}
        }
        
        return target+closet;
    }
};

int main(){
	Solution s;
	
	vector<int> num;
	num.push_back(-1);
	num.push_back(2);
	num.push_back(1);
	num.push_back(-4);
	
	cout<<s.threeSumClosest(num,-4)<<endl;;
}
