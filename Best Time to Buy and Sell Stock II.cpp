//
//
//description:
//可以进行无数次的交易，买在卖之前，最大收益多少
//
//solution:
//用一个p表示之前买进未卖出的物品价格，如果当前价格比之前高，就卖出，同时p等于当前价格
 
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iostream>

using namespace std;


class Solution {
public:
    int maxProfit(vector<int> &prices) {
    	if(prices.size()<=1)
    		return 0;
        int pro = 0;
        int p = prices[0];
        for(int i=1;i<prices.size();i++){
        	if(prices[i] > p)
        		pro += prices[i] -p;
        	p = prices[i];
        }
        
        return pro;
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
