/**************************
/*question��
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
/*������Ǹ����룬�����˼·�����ҹ���
/*��n=3Ϊ����
/*000 - 0
/*001 - 1
/*011 - 3
/*010 - 2
/*110 - 6
/*111 - 7
/*101 - 5
/*100 - 4
/*�鿴����֪��������ʱ���һλȡ����ż��ʱ���ұ�����һ��1��ߵ�һλȡ������
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
    	
    	int result_size = 1;                        //nλgray code�ĸ��� 
    	for(int i=0;i<n;i++)
    		result_size <<= 1;
    		
    	int gray_code = 0,gray_code_count=1;        //������ 
    	
    	result.push_back(gray_code);
        while(gray_code_count < result_size){
        	if(gray_code_count % 2){
        		gray_code = gray_code ^ 1;
        	}else{
        		int gray_code_copy = gray_code;
        		int xor_bit = 1;                     //��������һ��1��ߵ�һ����ȡ�� 
        		
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
