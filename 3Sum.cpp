//
//description:
//Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
//Find all unique triplets in the array which gives the sum of zero.
//
//Note:
//Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
//The solution set must not contain duplicate triplets.
//    For example, given array S = {-1 0 1 2 -1 -4},
//    A solution set is:
//    (-1, 0, 1)
//    (-1, -1, 2)
//
//solution:
//这道题目跟3sum closet一样，也是夹逼，不过这里要求的情况，如果当前i和i-1结果相同，就需要去重
//复杂度O(n^2) 

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
    	vector<vector<int> > res;
        sort(num.begin(),num.end());
        if(num.size() < 3)
        	return res;
        for(int i=0;i<=num.size()-3;i++){
        	if(i != 0 && num[i] == num[i-1])
        		continue;
        	int target = -num[i];
        	int j=i+1;
			int k=num.size()-1;
        	while(j<k){
        		if(num[j] + num[k] == target){
        			vector<int> line;
        			line.push_back(num[i]);
        			line.push_back(num[j]);
        			line.push_back(num[k]);
        			res.push_back(line);
        			for(;num[j] == num[j+1] && j <num.size()-1;j++);
        			j++;
        		}else if(num[j]+num[k] < target){
        			j++;
        		}else
        			k--;
        	}
        }
        
        return res;
    }
};

int main(){
	Solution s;
	
	vector<int> num;
	num.push_back(0); 
	num.push_back(0);
	num.push_back(0);
	/*num.push_back(2);
	num.push_back(-1);
	num.push_back(-4);*/
	
	vector<vector<int> > res = s.threeSum(num);
	for(int i=0;i<res.size();i++){
		for(int j=0;j<res[i].size();j++){
			cout<<res[i][j]<<" ";
		}
		cout<<endl;
	}
}
