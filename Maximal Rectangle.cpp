/*
/*question:
/*Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area.
/*
/*solution:
/*���Largest Rectangle in Histogram��˼�룬�����ΰ���X���л��֣����ÿһ��x��Histogramͼ
/*Ȼ�����Largest Rectangle in Historgam�㷨���������������
*/ 


//code:

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<stack>

using namespace std;

class Solution {
public:
	int L,W;
    int maximalRectangle(vector<vector<char> > &matrix) {
        int length = matrix.size();
        if(length == 0)
        	return 0;
        int width = matrix[0].size();
        int max_area = 0;
        for(int row=0;row<length;row++){
        	vector<int> col_vec;
        	for(int col=0;col<width;col++){
        		int count = 0;
        		for(int x=row;x<length && matrix[x][col] == '1';x++){
        			count++;
        		}
        		col_vec.push_back(count);
        	}
        	int area = largestRectangleHistogram(col_vec);
        	if(area > max_area)
        		max_area = area;
        }
        
        return max_area;
    }
    
    int largestRectangleHistogram(vector<int> v){
    	if(v.size() == 0)
    		return 0;
    	v.push_back(0);                   //����0��ȷ����֮ǰ�����и߶ȶ�pop���� 
    	stack<int> s;
    	int max_area = 0;
    	for(int i=0;i<v.size();i++){
    		if(s.empty() || v[i] >= v[s.top()])
    			s.push(i);
    		else{
    			int index = s.top();
    			s.pop();
    			int width = s.empty() ? i : (i-s.top()-1);  //��ǰֱ��ͼ�Ŀ�ȵ���ջ�ڱ����͵�������Ϊ��߽�
				                                            //Ŀǰ��ջ��Ԫ��С��������Ϊ�ұ߽磬��Ҫ-1
															//���ջΪ�գ�˵����ǰ�ڵ�����Ľڵ㣬���Ϊi 
    			int area = v[index] * width;
    			if(area > max_area)
    				max_area = area;
    			i--;
    		}
    	}
    	
    	return max_area;
    }
};


//test:

int main(){
	vector<vector<char> > matrix;
	/*vector<char> v1;
	v1.push_back('1');
	matrix.push_back(v1);*/
	
	Solution s;
	cout<<s.maximalRectangle(matrix)<<endl;
}
