/*
/*question:
/*Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. 
/*(each operation is counted as 1 step.)
/*You have the following 3 operations permitted on a word:
/*a) Insert a character
/*b) Delete a character
/*c) Replace a character
/*
/*solution:
/*利用dp的思想，这里解释dp的公式
/*dp[i,j]可以由dp[i-1,j],dp[i,j-1]和dp[i-1,j-1]通过增加一个数、删除一个数或者替换一个数，或者两个相等，i,j都+1
*/

//code: 

#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

class Solution {
public:
	int minvalue(int a,int b,int c){
		if(a<b){
			if(a<c)
				return a;
			else
				return c;
		}else{
			if(b < c)
				return b;
			else
				return c;
		}
	}
	
    int minDistance(string word1, string word2) {
    	int len1 = word1.length();
    	int len2 = word2.length();
    	if(len1 == 0)
    		return len2;
    	if(len2 == 0)
    		return len1;
    	int dp[len1+1][len2+1];
    	for(int row=0;row<=len1;row++)
    		dp[row][0] = row;
    	for(int col=0;col<=len2;col++)
    		dp[0][col] = col;
    		
    	for(int row=1;row<=len1;row++){
    		for(int col=1;col<=len2;col++){
    			int dist1,dist2,dist3;
    			if(word1[row-1] == word2[col-1])
    				dist3 = dp[row-1][col-1];
    			else
    				dist3 = dp[row-1][col-1]+1;
    			dist1 = dp[row-1][col] + 1;
    			dist2 = dp[row][col-1] + 1;
    			dp[row][col] = minvalue(dist1,dist2,dist3);
    		}
    	}
        
        return dp[len1][len2];
    }
};

int main(){
	string a="a";
	string b="a";
	
	Solution s;
	cout<<s.minDistance(a,b)<<endl;
}
