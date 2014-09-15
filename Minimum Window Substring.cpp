/*question:
/*Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).
/*For example,
/*S = "ADOBECODEBANC"
/*T = "ABC"
/*Minimum window is "BANC".
/*Note:
/*If there is no such window in S that covers all characters in T, return the emtpy string "".
/*If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.
/*
/*Solution：
/*这个的方法的复杂度是O(n)，采用了三个变量和两个数组，其中数组就是ascii的数组，一个叫find[256]一个叫need[256]
/*另还有三个变量begin,end,以及count，begin和end表示窗口的大小，
/*其中find就是记录窗口大小中找到的need字母的个数，need是用来统计T中各个字符情况的
/*首先我们可以找到一点点end，满足find中所有的字母都大于等于need所需字母，我们可以用count进行记录，如果当前一个字母是need需要的
/*而find的个数小于need的个数，我们就count++，find相应的字母也+1，否则count不加，find+1
/*找到end之后，我们需要确定begin的位置，如果need[begin]大于0，说明当前字母是需要，这个时候查看find[begin]，如果find[begin]>0
/*表示当前字母可以弃掉，否则begin的位置就定格了，因为当前窗口是满足need要求最小的情况之一
/*如果当前字母不是need所需的我们可以直接跳过，这样找到的第一个need[begin]同时find[begin]<need[begin]就是骑士位置
/*这样我们找到了一个窗口
/*但是可能存在多个这样的窗口
/*所以我们begin需要往后移动一个位置，然后再遍历end找一个一个新的满足条件的窗口后，再重复上述找begin的步骤
/*重复查找到结束，然后得到一个最小的窗口
*/

//code: 
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;

class Solution {
public:
    string minWindow(string S, string T) {
    	if(S.empty() || T.empty())
    		return "";
    	if(S.length() < T.length())
    		return "";
    		
        int find[256],need[256];
        
        memset(find,0,sizeof(find));
        memset(need,0,sizeof(need));
        for(int i=0;i<T.length();i++)
        	need[T[i]]++;
        	
        int left=-1,right=-1;
        int min = S.length();
        int begin = 0,end = 0;
        int cnt = 0;
        while(end < S.length()){
        	while(cnt < T.length() && end < S.length()){
        		if(need[S[end]] > 0){
        			find[S[end]]++;
        			if(find[S[end]] <= need[S[end]])
        				cnt++;
        		}
        		end++;
        	}
        	if(cnt < T.length())
        		break;
        		
        	
        	while(true){
        		if(need[S[begin]]){
        			if(find[S[begin]] > need[S[begin]])
        				find[S[begin]]--;
        			else
        				break;
        		}
        		begin++;
        	}
        	
        	if(end-begin <= min){
        		left = begin;
        		right = end;
        		mid = end - begin;
        	}
        	
        	
        	find[S[begin]]--;
        	begin++;
        	cnt--;
        }
        if(left == -1 || right == -1)
        	return "";
        return S.substr(left,right-left);
    }
};

int main(){
	Solution s;
	cout<<s.minWindow("cabwefgewcwaefgcf","cae")<<endl;
}
