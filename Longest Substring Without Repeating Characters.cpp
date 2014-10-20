//
//description:
//求最长字串，且字串字母不重复
//
//solution:
//用一个map[256]记录字母是否重复出现
//重复出现从前一个相应字母后边的位置开始计数
//遍历就最大值 

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int mp[256];
        memset(mp,-1,sizeof(mp));
        
        int max = 0;
        int cnt = 0;
        for(int i=0;i<s.length();i++){
        	if(mp[s[i]] < i - cnt){
        		cnt++;
        		if(cnt > max)
        			max = cnt;
        	}else{
        		cnt = i - mp[s[i]];
        	}
        	mp[s[i]] = i;
        }
        
        return max;
    }
};

int main(){
	Solution s;
	
	cout<<s.lengthOfLongestSubstring("")<<endl;
}
