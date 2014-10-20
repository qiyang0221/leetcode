//
//description:
//给定一个数组，同时给定一个目标数，求加起来等于target的两个数的下标 
//
//solution:
//map<int,int>逐个遍历，O(n)时间,O(n)空间 
 
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    /*vector<int> twoSum(vector<int> &numbers, int target) {
    	map<int,vector<int> > mp;
    	for(int i=0;i<numbers.size();i++){
    			mp[numbers[i]].push_back(i+1);
    	}
		sort(numbers.begin(),numbers.end());
		
        int i=0,j = numbers.size()-1;
        vector<int> res;
        while(i<j){
        	if(numbers[i] + numbers[j] == target){
        		int index1,index2;
        		if(numbers[i] != numbers[j]){
        			index1  = mp[numbers[i]][0];
        			index2 = mp[numbers[j]][0];
        		}else{
        			index1 = mp[numbers[i]][0];
        			index2 = mp[numbers[j]][1];
        		}
        		if(index1 > index2){
        			int tmp = index2;
        			index2 = index1;
        			index1 = tmp;
        		}
        		
        		res.push_back(index1);
        		res.push_back(index2);
        		return res;
        	}else if(numbers[i] + numbers[j] > target){
        		j--;
        	}else
        		i++;
        }
    }*/
    
    vector<int> twoSum(vector<int> &numbers, int target){
    	map<int,int> mp;
    	
    	for(int i=0;i<numbers.size();i++){
    		if(mp[target-numbers[i]] == 0){
    			mp[numbers[i]] = i+1;
    		}else{
    			vector<int> res;
    			res.push_back(mp[target-numbers[i]]);
    			res.push_back(i+1);
    			
    			return res;
    		}
    	}
    }
};

int main(){
	Solution s;
	vector<int> numbers;
	numbers.push_back(0);
	numbers.push_back(75);
	numbers.push_back(25);
	numbers.push_back(0);
	vector<int> res = s.twoSum(numbers,0);
	
	for(int i=0;i<res.size();i++)
		cout<<res[i]<<" ";
	cout<<endl;
}
