//
//description:
//在一个旋转的数组查找最小数，数组有重复
//
//solution:
//采用二分的方法，详细见代码
//这类题目如果采用二分的话，必须仔细考虑mid是否要加减1，因为很容易就跳过了最小数
//还有刚开始就需要判断l和r的大小，如果l小于r就直接返回结果就好
 
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int> &num) {
        int size = num.size();
        if(size == 1 || num[0] < num[size-1])
        	return num[0];
        int l=0,r=size-1;
        while(l < r){
        	if(num[l] < num[r])
        		return num[l];
        	int mid = (l+r)/2;
        	if(num[mid] < num[r])
        		r = mid;
        	else if(num[mid] > num[r]){
        		l = mid+1;
        	}else{
        		++l;
        		--r;
        	}
        }
        
        return num[(l+r)/2];
    }
};
int main(){
	
	vector<int> num;
	num.push_back(10);
	num.push_back(10);
	num.push_back(10);
	num.push_back(10);
	num.push_back(1);
		
	Solution s;
	cout<<s.findMin(num)<<endl;
}


