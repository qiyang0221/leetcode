/*
/*question:
/*Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area.
/*
/*solution:
/*借鉴Largest Rectangle in Histogram的思想，将矩形按照X进行划分，求得每一条x的Histogram图
/*然后调用Largest Rectangle in Historgam算法计算其最大矩形面积
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
    	v.push_back(0);                   //加入0，确保将之前的所有高度都pop出来 
    	stack<int> s;
    	int max_area = 0;
    	for(int i=0;i<v.size();i++){
    		if(s.empty() || v[i] >= v[s.top()])
    			s.push(i);
    		else{
    			int index = s.top();
    			s.pop();
    			int width = s.empty() ? i : (i-s.top()-1);  //当前直方图的宽度等于栈内比它低的索引作为左边界
				                                            //目前比栈顶元素小的索引作为右边界，需要-1
															//如果栈为空，说明当前节点是最矮的节点，宽度为i 
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
