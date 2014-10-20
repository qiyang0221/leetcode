//
//description:
//数独，9*9，每一行一列是1-9，每个3*3是1-9
//
//solution:
//dfs，先用数组记录每一个空格，同时用三个9*9记录每行、每列、每个3*3的访问情况
//复杂度O(9^k)，k表示空格个数 
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<cstring>

using namespace std;

class Solution {
public:
	vector<int> vec_x,vec_y,res;
    void solveSudoku(vector<vector<char> > &board) {
        vector<vector<bool> > row(9,vector<bool>(9,0));
        vector<vector<bool> > col(9,vector<bool>(9,0));
        vector<vector<bool> > block(9,vector<bool>(9,0));

        for(int x=0;x<9;x++){
        	for(int y=0;y<9;y++){
        		if(board[x][y] == '.'){
        			vec_x.push_back(x);
        			vec_y.push_back(y);
        		}else{
        			int value = board[x][y] - '1';
        			row[x][value] = true;
        			col[y][value] = true;
					int index = 3 * (x/3) + (y/3);
					block[index][value] = true;	
        		} 
        	}
        }
        
        dfs(row,col,block,0);
        
        for(int i=0;i<vec_x.size();i++){
        	int x = vec_x[i];
        	int y = vec_y[i];
        	board[x][y] = res[i] + '1';
        }
    }
    
    bool dfs(vector<vector<bool> > &row, vector<vector<bool> > &col, vector<vector<bool> > &block,int dep){
    	if(dep >= vec_x.size()){
    		return true;
    	}else{
    		int x = vec_x[dep];
			int y = vec_y[dep];
			int index = (x / 3) *3 + y / 3;
    		for(int i=0;i<9;i++){
    			if(!row[x][i] && !col[y][i] && !block[index][i]){
					row[x][i] = true;	
					col[y][i] = true;
					block[index][i] = true;
					res.push_back(i);
					if(!dfs(row,col,block,dep+1)){
						row[x][i] = false;	
						col[y][i] = false;
						block[index][i] = false;
						res.pop_back();
					}else{
						return true;
					}
				}
    		}
    	}
    }
};


int main(){
	vector<vector<char> > board;
	vector<char> line1(9,'.');
	vector<char> line2(9,'.');
	vector<char> line3(9,'.');
	vector<char> line4(9,'.');
	vector<char> line5(9,'.');
	vector<char> line6(9,'.');
	vector<char> line7(9,'.');
	vector<char> line8(9,'.');
	vector<char> line9(9,'.');
	
	line1[0] = '5';line1[1] = '3';line1[4] = '7';
	line2[0] = '6';line2[3] = '1';line2[4] = '9';line2[5] = '5';
	line3[1] = '9';line3[2] = '8';line3[7] = '6';
	line4[0] = '8';line4[4] = '6';line4[8] = '3';
	line5[0] = '4';line5[3] = '8';line5[5] = '3';line5[8] = '1';
	line6[0] = '7';line6[4] = '2';line6[8] = '6';
	line7[1] = '6';line7[6] = '2';line7[7] = '8';
	line8[3] = '4';line8[4] = '1';line8[5] = '9';line8[8] = '5';
	line9[4] = '8';line9[7] = '7';line9[8] = '9';
	
	board.push_back(line1);
	board.push_back(line2);
	board.push_back(line3);
	board.push_back(line4);
	board.push_back(line5);
	board.push_back(line6);
	board.push_back(line7);
	board.push_back(line8);
	board.push_back(line9);
	
	Solution s;
	s.solveSudoku(board);
	
	for(int i=0;i<board.size();i++){
		for(int j=0;j<board[i].size();j++)
			cout<<board[i][j]<<" ";
		cout<<endl;
	}
}
