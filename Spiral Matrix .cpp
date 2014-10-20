//
//description:
//比如3*3的矩阵，从外圈到内圈取值
//
//solution:
//找规律
//leetcode的题解思路比较清晰，定义beginx,endx,beginy,endy
//刚开始从x_begin-x_end -> y_begin-y_end -> x_end-x_begin -> y_end->y_begin
//然后x_begin++ y_begin++ x_end-- y_end--即可，思路比较清晰 
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<cstring>

using namespace std;

class Solution {
public:
	
        
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
    	vector<int> res;
    	
    	int length,width;
		int x_dir[4] = {0,1,0,-1};
	    int y_dir[4] = {1,0,-1,0};
    	
    	length = matrix.size();
    	if(length <= 0)
    		return res;
    	width = matrix[0].size();
    	if(width <= 0)
    		return res;
    		
    	int vis[length+2][width+2];
    	memset(vis,0,sizeof(vis));
    	for(int i=0;i<length+2;i++){
    		vis[i][0] = true;
    		vis[i][width+1] = true;
    	}
    	
    	for(int j=0;j<width+2;j++){
    		vis[0][j] = true;
    		vis[length+1][j] = true;
    	}
    	int num = width * length;
    	
    	int dir = 0;
    	int x = 1,y= 1;
    	for(int i=0;i<num;i++){
    		res.push_back(matrix[x-1][y-1]);
    		vis[x][y] = true;
    		for(int j=0;j<4;j++){
    			int xx = x + x_dir[dir];
    			int yy = y + y_dir[dir];
    			
    			if(!vis[xx][yy]){
    				x = xx;
    				y = yy;
    				break;
    			}
    				
    			dir = (dir + 1)%4;
    		}
    	}
    	
    	return res;
    }
};

int main(){
	Solution s;
	vector<vector<int> > matrix;
	/*vector<int> v1;
	v1.push_back(1);v1.push_back(2);v1.push_back(3);
	vector<int> v2;
	v2.push_back(4);v2.push_back(5);v2.push_back(6);
	vector<int> v3;
	v3.push_back(7);v3.push_back(8);v3.push_back(9);*/
	
	//matrix.push_back(v1);matrix.push_back(v2);matrix.push_back(v3);
	vector<int> res = s.spiralOrder(matrix);
	for(int i=0;i<res.size();i++)
		cout<<res[i]<<" ";
	cout<<endl;
}
