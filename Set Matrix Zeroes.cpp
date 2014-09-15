/*
/*question:
/*Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
/*
/*solution:
/*空间O(m+n)的方法，使用两个数组记录改行或者该列是否需要全部置0
/*O(1)的思路是利用本身矩阵第一行和第一列存储每行每列是否需要置零，再用两个变量存储第一行和第一列是否需要置零
*/

//code: 

#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
		    	        
        int ROW = matrix.size();
        if(ROW <= 0)
        	return;
        int COL = matrix[0].size();
        if(COL <= 0)
        	return;
        	
        bool rowFlag = false,colFlag = false;
        for(int i=0;i<ROW && !rowFlag;i++)
        	if(matrix[i][0] == 0)
        		rowFlag = true;
        for(int j=0;j<COL && !colFlag;j++)
        	if(matrix[0][j] == 0)
        		colFlag = true;
        		
        for(int i=1;i<ROW;i++){
        	for(int j=1;j<COL;j++){
        		if(matrix[i][j] == 0){
        			matrix[i][0] = 0;
        			matrix[0][j] = 0;
        		}
        	}
        }
        
        for(int i=1;i<ROW;i++){
        	if(matrix[i][0] == 0){
        		for(int j=1;j<COL;j++)
        			matrix[i][j] = 0;
        	}
        }   
        
        
        for(int j=1;j<COL;j++){
        	if(matrix[0][j] == 0){
        		for(int i=1;i<ROW;i++)
        			matrix[i][j] = 0;
        	}
        }
        
        if(rowFlag){
        	for(int i=0;i<ROW;i++)
        		matrix[i][0] = 0;
        }
        
        if(colFlag){
        	for(int j=0;j<COL;j++)
        		matrix[0][j] = 0;
        }
    }
};


int main(){
	Solution s;
	s.setZeroes();
}
