//
//description:
//判断一个给出的数独是否合法
//
//solution:
//给定三个9*9记录row、col、block访问记录
//判定是否合法
//复杂度O(n*n) 空间可以O(n*n)也可以O(1) 
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        vector<vector<bool> > row(9,vector<bool>(9,0));
        vector<vector<bool> > col(9,vector<bool>(9,0));
        vector<vector<bool> > block(9,vector<bool>(9,0));

        for(int x=0;x<9;x++){
        	for(int y=0;y<9;y++){
        		if(board[x][y] != '.'){
        			int index = 3 * (x/3) + (y/3);
        			int value = board[x][y] - '1';
        			if(!row[x][value] && !col[y][value] && !block[index][value]){
        				row[x][value] = true;
	        			col[y][value] = true;	
						block[index][value] = true;	
        			}else{
        				return false;
        			}
        		} 
        	}
        }
        
        return true;
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
	if(s.isValidSudoku(board)){
		cout<<"true"<<endl;
	}else{
		cout<<"false"<<endl;
	}
	
}
