//
//description:
//给定一个排列，求下一个排列
//
//solution:
//求得逆序数是的num[j] < num [i] 当j>i，从i开始遍历
 
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int len = num.size();
        if(len <= 0)
        	return;
        int i,j;
        bool find = false;
        for(i=len-1;i>=0;i--){
        	for(j=len-1;j>i;j--){
        		if(num[i] < num[j]){
        			int tmp = num[i];
        			num[i] = num[j];
        			num[j] = tmp;
        			find = true;
        			break;
        		}
       		}
       		if(find)
       			break;
        }
        
        if(find){
        	sort(num.begin()+i+1,num.end());
        }else{
        	sort(num.begin(),num.end());
        }
    }
};

int main(){
	vector<int> v;
	v.push_back(1);v.push_back(2);
	
	Solution s;
	s.nextPermutation(v);
	
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;
}
