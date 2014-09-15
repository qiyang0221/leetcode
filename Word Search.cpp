/*
/*question:
/*Given a 2D board and a word, find if the word exists in the grid.
/*The word can be constructed from letters of sequentially adjacent cell, 
/*where "adjacent" cells are those horizontally or vertically neighboring. 
/*The same letter cell may not be used more than once.
/*For example,
/*Given board =
/*[
/*  ["ABCE"],
/*  ["SFCS"],
/*  ["ADEE"]
/*]
/*
/*solution:
/*dfs,注意边界条件和访问vis的修改
*/

//code: 
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>

using namespace std;


class Solution {
public:
	int X,Y;
	bool flag;
	
	bool axisCheck(int x,int y){
		if(x >= 0 && x < X && y >= 0 && y < Y)
			return true;
		return false;
	}
	
	void dfs(vector<vector<char> > &board,vector<vector<bool> > &vis,string word,int depth,int x,int y){
		if(flag)
			return;
		
		if(depth >= word.length()){
			flag = true;
			return;
		}
		
		int x_dir[4] = {1,-1,0,0};
		int y_dir[4] = {0,0,1,-1};
		
		vis[x][y] = true;
		for(int i=0;i<4;i++){
			int x_cpy = x+x_dir[i];
			int y_cpy = y+y_dir[i];
			if(axisCheck(x_cpy,y_cpy)){
				if(!vis[x_cpy][y_cpy] && word[depth] == board[x_cpy][y_cpy]){
					dfs(board,vis,word,depth+1,x_cpy,y_cpy);
				}
			}
		}
		vis[x][y] = false;
	}
	
    bool exist(vector<vector<char> > &board, string word) {
    	
    	if(board.size() <= 0 || board[0].size() <= 0)
    		return false;
    	X = board.size();
    	Y = board[0].size();
    	if(word.empty() || word.size() == 0)
    		return true;
    	
    	vector<vector<bool> > vis(board.size(), vector<bool>(board[0].size(), false)); 
    	flag = false;
        for(int x=0;x < X;x++){
        	for(int y=0; y < Y;y++){
        		if(board[x][y] == word[0]){
        			dfs(board,vis,word,1,x,y);
					if(flag)
        				return true;
        		}
        	}
        }
        
        return false;
    }
};


int main(){
	vector<vector<char> > board;
	vector<char> line1;
	line1.push_back('A');line1.push_back('B');line1.push_back('C');line1.push_back('E');
	vector<char> line2;
	line2.push_back('S');line2.push_back('F');line2.push_back('C');line2.push_back('S');
	vector<char> line3;
	line3.push_back('A');line3.push_back('D');line3.push_back('E');line3.push_back('E');
	board.push_back(line1);
	board.push_back(line2);
	board.push_back(line3);
	
	Solution s;
	if(s.exist(board,"ABED")){
		cout<<"true"<<endl;
	}else{
		cout<<"false"<<endl;
	}
}
