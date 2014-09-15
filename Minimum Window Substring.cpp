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
/*Solution��
/*����ķ����ĸ��Ӷ���O(n)�������������������������飬�����������ascii�����飬һ����find[256]һ����need[256]
/*������������begin,end,�Լ�count��begin��end��ʾ���ڵĴ�С��
/*����find���Ǽ�¼���ڴ�С���ҵ���need��ĸ�ĸ�����need������ͳ��T�и����ַ������
/*�������ǿ����ҵ�һ���end������find�����е���ĸ�����ڵ���need������ĸ�����ǿ�����count���м�¼�������ǰһ����ĸ��need��Ҫ��
/*��find�ĸ���С��need�ĸ��������Ǿ�count++��find��Ӧ����ĸҲ+1������count���ӣ�find+1
/*�ҵ�end֮��������Ҫȷ��begin��λ�ã����need[begin]����0��˵����ǰ��ĸ����Ҫ�����ʱ��鿴find[begin]�����find[begin]>0
/*��ʾ��ǰ��ĸ��������������begin��λ�þͶ����ˣ���Ϊ��ǰ����������needҪ����С�����֮һ
/*�����ǰ��ĸ����need��������ǿ���ֱ�������������ҵ��ĵ�һ��need[begin]ͬʱfind[begin]<need[begin]������ʿλ��
/*���������ҵ���һ������
/*���ǿ��ܴ��ڶ�������Ĵ���
/*��������begin��Ҫ�����ƶ�һ��λ�ã�Ȼ���ٱ���end��һ��һ���µ����������Ĵ��ں����ظ�������begin�Ĳ���
/*�ظ����ҵ�������Ȼ��õ�һ����С�Ĵ���
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
