//
//description:
//���Խ������ν��ף�һ�γ���һֻ��Ʊ��������֮ǰ�����������
//solution:
//��һ������f[i]��ʾ��0-i�ܻ�ȡ�����������g[i]��ʾi��size-1���������
//Ȼ���ٱ���һ�����������max(f[i]+g[i])
//�����Ŀ�տ�ʼ��������˼�����ͬʱ���Գ�����ֻ��Ʊ�������Ŀ�ͱ�����
//��Ҫһ��m,mm��ʾ֮ǰ����Сֵ����Сֵ��Ȼ��ѡ��i,j������������� 

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
