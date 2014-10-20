#include<iostream>
//
//description:
//给定一个字符串，按照zigzag顺序转换，最后返回结果 
#include<cstdio>
#include<cstdlib>
#include<vector>

using namespace std;


class Solution {
public:
    string convert(string s, int nRows) {
    	if(nRows <= 1)
    		return s; 
        vector<string> vec(nRows);
        
        int i = 0;
        int row = 0;
        int dir = 1;
        while(i < s.length()){
        	vec[row].push_back(s[i]);
        	if(row == 0){
        		dir = 1;
        	}else if(row== nRows-1){
        		dir = -1;
        	}
        	row += dir;
        	i++;
        }
        
        string res;
        for(int i=0;i<nRows;i++)
        	res += vec[i];
        	
        return res;
    }
};

int main(){
	Solution s;
	
	cout<<s.convert("PAYPALISHIRING",4)<<endl;
}
