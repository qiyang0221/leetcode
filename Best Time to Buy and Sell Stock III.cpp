//
//description:
//可以进行两次交易，一次持有一只股票，卖在买之前，求最大利润
//solution:
//用一个数组f[i]表示从0-i能获取的最大利润，用g[i]表示i到size-1的最大利润
//然后再遍历一遍求最大利润max(f[i]+g[i])
//这道题目刚开始理解错了意思，如果同时可以持有两只股票，这道题目就变难了
//需要一个m,mm表示之前次最小值，最小值，然后选择i,j卖出的最大收益 

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<algorithm>

using namespace std;


class Solution {
public:
	int maxProfit(vector<int> &prices) {
		int size = prices.size();
		
		if(size < 2)
			return 0;
		int f[size],g[size];
		int valley = prices[0];
		f[0] = 0;
		for(int i=1;i<size;i++){
			valley = min(valley,prices[i]);
			f[i] = max(f[i-1],prices[i]-valley);
		}

		int peak = prices[size-1];
		g[size-1] = 0;
		for(int i=size-2;i>=0;i--){
			peak = max(peak,prices[i]);
			g[i] = max(g[i+1],peak-prices[i]);
		}
		
		int max = 0;
		for(int i=0;i<size;i++)
			if(f[i]+g[i]>max)
				max = f[i]+g[i];
		return max;
	}
    /*int maxProfit(vector<int> &prices) {
    	int size = prices.size();
    	if(size <= 1)
    		return 0;
    	int max = 0;
    	const int INF = 0x3f3f3f3f;
        int m=INF,mm=prices[0];
        for(int i=1;i<size;i++){
        	int val = prices[i]-mm;
        	if(val>max)
        		max = val;
        		
    		int m_tmp = m;
        	for(int j=i+1;j<size;j++){
    			if(prices[j] - m_tmp + val > max)
    				max = prices[j] - m_tmp + val;
        		if(prices[j] < m_tmp)
        			m_tmp = prices[j];
        	}
        	
        	if(prices[i] <= mm){
        		m = mm;
        		mm = prices[i];
        	}else if(m == -1 || (prices[i]> mm && prices[i]<m)){
        		m = prices[i];
        	}
        }
        
        return max;
    }*/
};


int main(){
	vector<int> prices;
	prices.push_back(1);
	prices.push_back(2);
	//prices.push_back(3);
	//prices.push_back(4);
	/*prices.push_back(4);
	prices.push_back(8);
	prices.push_back(11);*/
	
	Solution s;
	cout<<s.maxProfit(prices)<<endl;
}
