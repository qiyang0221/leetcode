/*
/*question:
/*Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, 
/*find the area of largest rectangle in the histogram.
/*Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].
/*The largest rectangle is shown in the shaded area, which has area = 10 unit.
/*For example,
/*Given height = [2,1,5,6,2,3],
/*return 10.
/*
/*solution:
/*这道题目最简单的方法就是，以当前直方图为高度，向左右两边扩展，获取当前高度的最大宽度，就可以求当前高度的矩形的最大面积
/*复杂度是O(n^2)
/*看别的想法利用单调栈，遍历所有的高度，如果当前的高度小于栈内高度，那么就pop出top来，计算它的高度
/*栈的思想跟上述方法一样，找到小于当前栈高度的边其实就是找到了右边的终点，而左边的终点就是栈下的位置，如果为空，那么左边的终点就是起点
/*这种思路的复杂度小于O(n^2)，因为每次不需要求当前直方图的左右边界，求左右边界的复杂度为1
*/

//code: 

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<stack>
#include<vector>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        stack<int> s;
        height.push_back(0);
        int size = height.size();
        if(size == 0)
        	return 0;
        int max_area = 0;
        for(int i=0;i<size;i++){
        	if(s.empty() || height[i] >= height[s.top()]){
        		s.push(i);
        	}else{
    			int index = s.top();
    			s.pop();
    			int width = s.empty() ? i : (i-s.top() - 1);
    			int area = width * height[index];
    			if(area > max_area)
    				max_area = area;
        		i--;
        	}
        	
        }
        
        return max_area;
    }
};

using namespace std;

//test:
int main(){
	vector<int> v;
	v.push_back(4);
	v.push_back(2);
	v.push_back(0);
	v.push_back(3);
	v.push_back(2);
	v.push_back(5);
	
	Solution s;
	cout<<s.largestRectangleArea(v)<<endl;
}
