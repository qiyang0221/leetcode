//
//description:
//给定N,将1-N^2按照spiral matrix顺序存储
//
//solution:
//同spiral matrix一样
 
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        
		vector<vector<int> > res(n,vector<int>(n,-1));
    	
    	if(n <= 0)
    		return res;
    		
		int x_dir[4] = {0,1,0,-1};
	    int y_dir[4] = {1,0,-1,0};
	    
    	int num = n * n;
    	
    	int dir = 0;
    	int x = 0,y= 0;
    	for(int i=1;i<=num;i++){
    		
    		res[x][y] = i;
    		for(int j=0;j<4;j++){
    			int xx = x + x_dir[dir];
    			int yy = y + y_dir[dir];
    			
    			if((xx >=0 && xx < n) && (yy >=0 && yy < n)&& res[xx][yy] < 0){
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
	s.generateMatrix(1);
}
