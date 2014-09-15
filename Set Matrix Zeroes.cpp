/*
/*question:
/*Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
/*
/*solution:
/*�ռ�O(m+n)�ķ�����ʹ�����������¼���л��߸����Ƿ���Ҫȫ����0
/*O(1)��˼·�����ñ�������һ�к͵�һ�д洢ÿ��ÿ���Ƿ���Ҫ���㣬�������������洢��һ�к͵�һ���Ƿ���Ҫ����
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
