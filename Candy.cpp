//
//description:
//给定一列排名，排名高的一定要比排名低的同学拿更多的糖果，每个人最少拿一个糖果
//求最少给多少糖果 
//solution:
//代码给的是求波谷，然后求最优边界，不是最优
//最优复杂度就是扫一遍
 
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<cstring>

using namespace std;

class Solution {
public:
    int candy(vector<int> &ratings) {
        int size = ratings.size();
        if(size == 0)
        	return 0;
        if(size == 1)
        	return 1;
        
        int c[size];
        memset(c,-1,sizeof(c));
        int i = 0;
        while(i<size){
        	while(true){
        		if((i == 0 && ratings[i] <= ratings[i+1]) ||
					(i == size-1 && ratings[i] <= ratings[i-1]) ||
					(ratings[i] <= ratings[i-1] && ratings[i] <= ratings[i+1]))
					break;
				i++;
        	}
        	
        	c[i] = 1;
        	int left = i-1,right = i+1;
        	while(left >= 0 && ratings[left] > ratings[left+1]){
    			c[left] = (c[left+1]+1) > c[left] ? (c[left+1]+1) : c[left];
    			left--;
        	}
        	
        	while(right <size && ratings[right] > ratings[right-1]){
    			c[right] = (c[right-1]+1) > c[right] ? (c[right-1]+1) : c[right];
    			right++;
        	}
        	i = right;
        }
        
        int sum = 0;
        for(int i=0;i<size;i++)
        	sum += c[i];
        return sum;
    }
};

int main(){
	vector<int> ratings;
	ratings.push_back(1);
	ratings.push_back(2);
	ratings.push_back(2);
	ratings.push_back(2);
	ratings.push_back(1);
	/*ratings.push_back(1);
	ratings.push_back(7);
	ratings.push_back(3);*/
	
	Solution s;
	cout<<s.candy(ratings)<<endl;
} 
