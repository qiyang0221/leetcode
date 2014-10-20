//
//description:
//给一个数组表示的数字，求+1的结果
//
//solution:
//考虑进位等情况
 
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>

using namespace std;


class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
		if(digits.size() <= 0)
         	return digits;
        int end = digits.size() - 1;
        int carry = (digits[end] + 1) / 10;
        digits[end] = (digits[end] + 1) % 10;
        for(int i = end - 1;i>=0 && carry;i--){
        	digits[i] = digits[i] + carry;
        	carry = digits[i] / 10;
        	digits[i] = digits[i] % 10;
        }
        if(carry){
        	digits.insert(digits.begin(),carry);
        }
        
        return digits;
    }
};

int main(){
	vector<int> digits;
	digits.push_back(0);
	Solution s;
	
	vector<int> result = s.plusOne(digits);
	for(int i=0;i<result.size();i++)
		cout<<result[i];
	cout<<endl;
}
