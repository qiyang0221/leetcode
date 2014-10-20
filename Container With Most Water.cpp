//
//description:
//给定一个数组，表示一条与y轴平行的线，数值表示高度
//求两条线i,j，能圈最多的水
//
//solution:
//取任意两点i,j如果height[i]<height[j]，那么只有height[i]向内移动，
//否则，向内移动height[j]，面积越来越小
//i,j分别为0和size-1 

#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
    	int max_area = 0;
    	int i = 0,j = height.size()-1;
    	while(i<j){
    		int area;
    		if(height[i] < height[j]){
    			area = height[i] * (j-i);
    			i++;
    		}else{
    			area = height[j] * (j-i);
    			j--;
    		}
    		if(area > max_area)
    			max_area = area;
    	}
    	
    	return max_area;
    }
};

int main(){
	vector<int> height;
	/*height.push_back(1);
	height.push_back(2);
	height.push_back(1);
	height.push_back(0);
	height.push_back(2);
	height.push_back(1);
	height.push_back(0);
	height.push_back(1);
	height.push_back(3);
	height.push_back(2);
	height.push_back(1);
	height.push_back(2);
	height.push_back(3);*/
	
	Solution s;
	cout<<s.maxArea(height)<<endl;
}
