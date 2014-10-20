//
//description:
//将罗马数字转换成整数
//
//solution:
//设置字母到整数的hash
//然后从字母的最优往前逐渐加
//如果hash[i] < hash[i+1] res -= hash[i] 否则 res += hash[i] 


#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
    	if(s.length() <= 0)
    		return 0;
        map<char,int> mp;
        mp['I'] = 1;
		mp['V'] = 5;
        mp['X'] = 10;
		mp['L'] = 50;
        mp['C'] = 100;
		mp['D'] = 500;
        mp['M'] = 1000;
        
        int i = s.length()-1;
        int res = mp[s[i--]];
        while(i>=0){
        	if(mp[s[i]] < mp[s[i+1]]){
        		res -= mp[s[i]];
        	}else
        		res += mp[s[i]];
        	i--;
        }
        
        return res;
    }
};

int main(){
	Solution s;
	
	cout<<s.romanToInt("XXX")<<endl;
}
