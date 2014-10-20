//
//description:
//给一个数组，第i个元素表示第i天的价格，求进行一次交易，获得的最大收益,买在卖之前 
//
//solution:
//用一个变量记录i之前的最小值，然后逐个遍历，求得最大收益
 

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>

using namespace std;


class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int size = prices.size();
        if(size == 0)
        	return 0;
        int dp[size];
        int min = dp[0] = prices[0];
        int max = 0;
        for(int i=1;i<size;i++){
        	if(prices[i]-min > max)
        		max = prices[i]-min;
        	if(prices[i]<min)
        		min = prices[i];
        }
        
        return max;
    }
};


int main(){
	vector<int> prices;
	prices.push_back(1);
	prices.push_back(4);
	prices.push_back(7);
	prices.push_back(5);
	prices.push_back(8);
	prices.push_back(11);
	
	Solution s;
	cout<<s.maxProfit(prices)<<endl;
}
