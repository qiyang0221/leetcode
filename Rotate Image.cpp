//
//description:
//图像顺时针旋转90°
//
//solution:
//找规律，按照正方形进行反转，从最外层到里层
//i从0到n/2,确定正方形
//len确定长度len = len-2进行递减
//然后按照列遍历j属于[i,i+len)
//交换四次结果x,y是起始位置 xx,yy是目标位置 
//xx = y yy = (len-1) - x 即可

//leetcode题解的思路是先沿东北方向对角线对折，然后在沿水平对角线反转
//或者先水平对折再沿西北方向对角线对折 
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        if(matrix.size() == 0 || matrix.size() == 1)
        	return ;
        int size = matrix.size();
        int circle = size / 2;
        int cir_len = size;
        int x_start,y_start;
        for(int x_start=y_start=0;x_start < circle;x_start++,y_start++){
        	int x= x_start,y=y_start;
        	for(int i=0;i<cir_len-1;i++){
        		int tmp,last = matrix[x][y];
        		for(int j=0;j<4;j++){
        			int xx = y;
        			int yy = (size - 1) - x;
        			tmp = matrix[xx][yy];
        			matrix[xx][yy] = last;
        			last = tmp;
        			x = xx;
        			y = yy;
        		}	
        		y++;
        	}
        	cir_len -=2;
        }
    }
    
    void print(vector<vector<int> > &matrix){
    	for(int i=0;i<matrix.size();i++){
			for(int j=0;j<matrix[i].size();j++){
				cout<<matrix[i][j]<<" ";
			}
			cout<<endl;
		}
    }
};

int main(){
	vector<vector<int> > matrix;
	vector<int> line1;
	vector<int> line2;
	vector<int> line3;
	vector<int> line4;
	vector<int> line5;
	line1.push_back(1);line1.push_back(2);line1.push_back(3);line1.push_back(4);line1.push_back(5);
	line2.push_back(6);line2.push_back(7);line2.push_back(8);line2.push_back(9);line2.push_back(10);
	line3.push_back(11);line3.push_back(12);line3.push_back(13);line3.push_back(14);line3.push_back(15);
	line4.push_back(16);line4.push_back(17);line4.push_back(18);line4.push_back(19);line4.push_back(20);
	line5.push_back(21);line5.push_back(22);line5.push_back(23);line5.push_back(24);line5.push_back(25);
	matrix.push_back(line1);
	matrix.push_back(line2);
	matrix.push_back(line3);
	matrix.push_back(line4);
	matrix.push_back(line5);
	
	Solution s;
	s.rotate(matrix);
	for(int i=0;i<matrix.size();i++){
		for(int j=0;j<matrix[i].size();j++){
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
}
