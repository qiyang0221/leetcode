//
//description:
//����ִ������ִ���ĸ���ظ�
//
//solution:
//��һ��map[256]��¼��ĸ�Ƿ��ظ�����
//�ظ����ִ�ǰһ����Ӧ��ĸ��ߵ�λ�ÿ�ʼ����
//���������ֵ 

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
