/*
/*question:
/*A message containing letters from A-Z is being encoded to numbers using the following mapping:
/*'A' -> 1
/*'B' -> 2
/*...
/*'Z' -> 26
/*Given an encoded message containing digits, determine the total number of ways to decode it.
/*For example,
/*Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
/*The number of ways decoding "12" is 2.
/*
/*solution:
/*利用归并的思想ab=a*b + (a-1)*(b-1)如果a的最后一位跟b的第一位可以组成新的字母
/*注意:这里有几个trick,首先如果a.len = 1需要判定a是否为0,0没有对应的字母 
*/ 

//code:
 
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>

using namespace std;

const int M = 1000;

class Solution {
public:
	
    int numDecodings(string s) {
    	int size = s.size();
    	if(size == 0)
    		return 0;
    	if(size == 1){
    		if(s[0] > '0' && s[0] <= '9')
    			return 1;
    		return 0;
    	}else{
    		int middle = size / 2;             // partion postion
    		int way_count = 0;
    		
			way_count = way_count + numDecodings(s.substr(0, middle)) * numDecodings(s.substr(middle)); // ab += a * b 
			
			int middle_value = (s[middle-1] - '0');   //AabB= A * B if ab is character
			if(middle_value >= 1 && middle_value <= 2){
				middle_value = middle_value * 10 + s[middle] - '0';
				if(middle_value >= 1 && middle_value <= 26){
					if(middle > 1 && middle +1 < size){
						way_count = way_count + numDecodings(s.substr(0, middle-1)) * numDecodings(s.substr(middle+1));
					}else if(middle > 1){
						way_count = way_count + numDecodings(s.substr(0, middle-1));
					}else if(middle + 1 < size){
						way_count = way_count + numDecodings(s.substr(middle+1));
					}else{
						way_count += 1;
					}
				}
			}
			
			return way_count;
    	}
    }
};

//test:
 
int main(){
	string str("123");
	Solution s;
	cout<<s.numDecodings(str)<<endl;
}
