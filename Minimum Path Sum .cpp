//
//description:
//求左上角走到右下角的最短距离
//每次仅可以向右或者向下走
//
//solution:
//dp 

#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
    	int ROW = grid.size();
    	if(ROW <= 0)
    		return 0;
    	int COL = grid[0].size();
    	if(COL <= 0)
    		return 0;
        
        int dp[ROW][COL];
        
        dp[0][0] = grid[0][0];
        for(int row=1;row<ROW;row++){
        	dp[row][0] = dp[row-1][0] + grid[row][0];
        }
        
        for(int col=1;col<COL;col++){
        	dp[0][col] = dp[0][col-1] + grid[0][col];
        }
        
        for(int col=1;col<COL;col++){
        	for(int row=1;row<ROW;row++){
        		dp[row][col] = (dp[row-1][col] < dp[row][col-1] ? dp[row-1][col] : dp[row][col-1]) + grid[row][col];
        	}
        }
        
        return dp[ROW-1][COL-1];
    }
};

int main(){
	Solution s;
	vector<int> a1;
	a1.push_back(1);
	a1.push_back(2);
	vector<int> a2;
	a2.push_back(1);
	a2.push_back(1);
	
	vector<vector<int> >grid;
	grid.push_back(a1);
	grid.push_back(a2);
	
	cout<<s.minPathSum(grid)<<endl;
}
