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
