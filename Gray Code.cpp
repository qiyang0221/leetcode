/**************************
/*question：
/*The gray code is a binary numeral system where two successive values differ in only one bit.
/*Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code.
/*A gray code sequence must begin with 0.
/*For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:
/*00 - 0
/*01 - 1
/*11 - 3
/*10 - 2
/*
/*solution:
/*该题就是格雷码，解题的思路就是找规律
/*以n=3为例：
/*000 - 0
/*001 - 1
/*011 - 3
/*010 - 2
/*110 - 6
/*111 - 7
/*101 - 5
/*100 - 4
/*查看规律知道：奇数时最后一位取反，偶数时自右边数第一个1左边的一位取反即可
*/
//code:
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
    	vector<int> result;
    	
    	int result_size = 1;                        //n位gray code的个数 
    	for(int i=0;i<n;i++)
    		result_size <<= 1;
    		
    	int gray_code = 0,gray_code_count=1;        //格雷码 
    	
    	result.push_back(gray_code);
        while(gray_code_count < result_size){
        	if(gray_code_count % 2){
        		gray_code = gray_code ^ 1;
        	}else{
        		int gray_code_copy = gray_code;
        		int xor_bit = 1;                     //自右数第一个1左边第一个数取反 
        		
        		while(!(gray_code_copy & 1)){       
        			gray_code_copy >>= 1;
        			xor_bit <<=1 ;
        		}
        		xor_bit <<= 1;
        		gray_code = gray_code ^ xor_bit;
        	}
        	
        	result.push_back(gray_code);
        	gray_code_count++;
        }
        
        return result;
    }
};
