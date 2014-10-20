//
//description:
//求旋转有序序列最小数
//
//solution:
//二分，这里有个细节就是可能没有旋转，那么直接返回num[0]即可 
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int> &num) {
        int size = num.size();
        if(size == 1)
        	return num[0];
        int left = 0,right = size-1;
        if(num[0] < num[size-1])
        	return num[0];
        while(left < right){
        	int mid = (left + right)/2;
        	if(num[mid] == num[left] || num[mid] == num[right]){
        		return num[left]<num[right]?num[left]:num[right]; 
        	}else if(num[mid] > num[left]){
        		left = mid;
        	}else if(num[mid] < num[right]){
        		right = mid;
        	}
        }
    }
};


int main(){
	Solution s;
	
	vector<int> num;
	num.push_back(3);
	num.push_back(2);
	num.push_back(1);
	
	cout<<s.findMin(num)<<endl;
} 
