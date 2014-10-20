//
//description:
//��һ���ַ�����������ִ� 
//
//solution:
//�����Ŀ��򵥵�˼·����dp,dp[i][j] = dp[i+1][j-1] && S[i] == S[j]�����Ӷ�O(n^2) 
//����һ��˼·��Mancher�㷨
//������赱ǰ��Ļ�������id�ԳƵģ��ұ߽���mx
//�������p[i]��i��p[j]���ұߣ�i��j����id�Գ�
//���p[j]<mx-i����ôp[i] = p[j] < mx-i
//���p[j]>=mx-i,��ôp[i]������mx-i
//����p[i] = min(p[2*id-i],mx-i)��Ȼ�������չ
//����µ�i+p[i] > mx��ôʣ�µ�id = i,mx = i+p[i]
//�������һ�¸��Ӷȣ� 
//while(str[i+p[i]] == str[i-p[i]]){p[i]++;}
//��һ����i+p[i]���Ǵ�mx������չ�ģ�����mxһֱ�ǵ����ģ�����mx����չ�����Ե�,��mx=n�Ͳ��ٽ�����չ
//����ʣ�µ��ַ����������Ҳ��mx-i
//���Ը��Ӷ���O(n) 

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>

using namespace std;

class Solution {
public:
    /*string longestPalindrome(string s) {
        int len = s.length();
        if(len <= 0)
        	return "";
        	
        bool dp[len][len];
        for(int i=0;i<len;i++)
        	dp[i][0] = true;
        int gap = 1;
        string res = s.substr(0,1);
        for(int gap=1;gap<len;gap++){
        	for(int i=0;i<len-gap;i++){
        		if(s[i] == s[i+gap] && ((i+1 > i+gap-1) || dp[i+1][gap-2])){
        			dp[i][gap] = true;
        			res = s.substr(i,gap+1);
        		}
        	}
        }
        
        return res;
    }*/
    
    string longestPalindrome(string s){
    	if(s.length() <= 1)
    		return s;
    		
    	string str = preProcess(s);
    	
    	int id = 0,mx = 0;
    	int len = str.length();
    	vector<int> p(len,0);
    	
    	for(int i=1;i<len-1;i++){
    		p[i] = mx > i ? min(p[2*id-i],mx-i) : 1;
    		
    		while(str[i+p[i]] == str[i-p[i]]){
    			p[i]++;
    		} 
    		
    		if(i+p[i] > mx){
    			mx = i+p[i];
    			id = i;
    		}
    	}
    	
    	int max = 0;
    	int index;
    	for(int i=1;i<len-1;i++){
    		if(p[i] > max){
    			max = p[i];
    			index = i;
    		}
    	}
    	
    	return s.substr((index-max)/2,max-1);
    }
    
    string preProcess(const string &s){
    	string res;
    	res.push_back('$');
    	res.push_back('#');
    	
    	for(int i=0;i<s.length();i++){
    		res.push_back(s[i]);
    		res.push_back('#');
    	}
    	
    	res.push_back('^');
    	
    	return res;
    }
};

int main(){
	Solution s;
	cout<<s.longestPalindrome("aaaaaaaaaaaaaaaaaaaaaaaa")<<endl;
}
