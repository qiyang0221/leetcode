//
//description:
//������������,gas��cost�����ܷ��һ�������������������ص�ԭ��λ��
//
//soltuion:
//��һ��left��¼��һ��ʣ������,start��¼��ʵλ��
//���������kʱleftС��0����ôstart = k+1
//��Ϊ֮ǰ����һ���㶼û�취�߹���k����
//
//������һ��֮�󣬵õ�һ������ܱ���һ���start�㣬
//Ȼ������￪ʼ���ж��ܷ�ص�ԭ��
 
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
