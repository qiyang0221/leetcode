//
//description:
//给定两个数组,gas和cost，求能否从一个点出发逐个往下走最后回到原来位置
//
//soltuion:
//用一个left记录上一步剩余汽油,start记录其实位置
//如果遍历到k时left小于0，那么start = k+1
//因为之前任意一个点都没办法走过第k个点
//
//当遍历一遍之后，得到一个最可能遍历一遍的start点，
//然后从这里开始，判断能否回到原点
 
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<cstring>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    	int size = gas.size();
    	
    	int left = 0;
    	int start = 0;
    	for(int i=0;i<size;i++){
    		left = left + gas[i] - cost[i];
    		if(left < 0){
    			start = i+1;
    			left = 0;
    		}
    	}
    	
    	left = 0;
    	for(int i=start;i<size+start;i++){
    		int pos = i % size;
    		left = left + gas[pos] - cost[pos];
    		if(left < 0)
    			break;
    	}
        if(left >= 0)
        	return start;
        else
        	return -1;
    }
};

int main(){
	Solution s;
	
	vector<int> gas;
	vector<int> cost;
	
	gas.push_back(4);
	/*gas.push_back(2);
	gas.push_back(5);
	gas.push_back(3);
	gas.push_back(3);*/
	
	cost.push_back(5);
	/*cost.push_back(2);
	cost.push_back(6);
	cost.push_back(4);
	cost.push_back(1);*/
	
	cout<<s.canCompleteCircuit(gas,cost)<<endl;
} 
