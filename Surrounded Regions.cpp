//
//description:
//给定一个矩阵有X,O组成，如果O周围都是X那么把O替换成X，求最终矩阵
//
//solution：
//这道题目如果用dfs，由于函数调用占用内存超出
//采用bfs，时间空间复杂度都是矩阵大小
 
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<queue>

using namespace std;

int x_dir[] = {-1,1,0,0};
int y_dir[] = {0,0,1,-1};
class Solution {
public:
	int row;
	int col;
	
    void solve(vector<vector<char> > &board) {
    	row = board.size();
    	if(row<=0)
    		return;
    	col = board[0].size();
    	if(col <= 0)
    		return;
    	queue<int> q;
		for(int x=0;x<row;x++){
			if(board[x][0] == 'O')
				q.push(x*col);
			if(board[x][col-1] == 'O')
				q.push(x*col+col-1);
		}
		
		for(int y=0;y<col;y++){
			if(board[0][y] == 'O')
				q.push(y);
			if(board[row-1][y] == 'O')
				q.push((row-1)*col+y);
		}
		
		while(!q.empty()){
			int index = q.front();
			q.pop();
			int x = index / col;
			int y = index % col;
			board[x][y] = '+';
	    	for(int i=0;i<4;i++){
	    		int xx = x + x_dir[i];
	    		int yy = y + y_dir[i]; 
	    		if(valid(xx,yy) && board[xx][yy] == 'O')
	    			q.push(xx*col+yy);
	    	}
		}
		for(int x=0;x<row;x++){
			for(int y=0;y<col;y++){
				if(board[x][y] == '+')
					board[x][y] = 'O';
				else
					board[x][y] = 'X';
			}
		}  
    }
    
    /*void dfs(vector<vector<char> > &board,int x,int y){
    	board[x][y] = '+';
    	for(int i=0;i<4;i++){
    		int xx = x + x_dir[i];
    		int yy = y + y_dir[i]; 
    		if(valid(xx,yy) && board[xx][yy] == 'O')
    			dfs(board,xx,yy);
    	}
    }*/
    
    bool valid(int x,int y){
    	if(x>=0 && x <row && y>=0 && y<col)
    		return true;
    	return false;
    }
};

int main(){
	vector<vector<char> > board;
	vector<char> line1;
	line1.push_back('X');line1.push_back('X');line1.push_back('X');line1.push_back('X');
	vector<char> line2;
	line2.push_back('X');line2.push_back('O');line2.push_back('O');line2.push_back('X');
	vector<char> line3;
	line3.push_back('X');line3.push_back('X');line3.push_back('O');line3.push_back('X');
	vector<char> line4;
	line4.push_back('X');line4.push_back('O');line4.push_back('X');line4.push_back('O');
	
	board.push_back(line1);
	board.push_back(line2);
	board.push_back(line3);
	board.push_back(line4);
	
	Solution s;
	s.solve(board);
	for(int x=0;x<board.size();x++){
		for(int y=0;y<board[x].size();y++){
			cout<<board[x][y]<<" ";
		}
		cout<<endl;
	}
} 
