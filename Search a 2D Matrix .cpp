/*
/*question:
/*Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
/*Integers in each row are sorted from left to right.
/*The first integer of each row is greater than the last integer of the previous row.
/*For example,
/*Consider the following matrix:
/*[
/*  [1,   3,  5,  7],
/*  [10, 11, 16, 20],
/*  [23, 30, 34, 50]
/*]
/*
/*solution:
/*二分法确定位置
*/

//code: 
Given target = 3, return true.
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<vector>

using namespace std;


class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        
        if(matrix.size() == 0 || matrix[0].size() == 0)
        	return false;
        
        int up = 0;
        int down = matrix.size()-1;
        int mid_x;
        while(up <= down){
        	mid_x = (up+down)/2;
        	if(matrix[mid_x][0] == target)
        		return true;
        	if(matrix[mid_x][0] < target)
        		up = mid_x + 1;
        	else
        		down = mid_x - 1;
        }
        
        if(matrix[mid_x][0] > target)
        	mid_x = mid_x - 1;
        if(mid_x < 0)
        	return false;
        
        int left = 0;
        int right = matrix[0].size()-1;
        int mid_y;
        while(left <= right){
        	mid_y = (left + right)/2;
        	if(matrix[mid_x][mid_y] == target)
        		return true;
        	if(matrix[mid_x][mid_y] < target)
        		left = mid_y + 1;
        	else
        		right = mid_y - 1;
        }
        
        return false;
    }
};


int main(){
	vector<vector<int> > matrix;
	vector<int> v1;
	v1.push_back(1);
	matrix.push_back(v1);
	
	Solution s;
	if(s.searchMatrix(matrix,2))
		cout<<"true"<<endl;
	else
		cout<<"false"<<endl;
}
