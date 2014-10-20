//
//description:
//��һ������ĸ���ֳ��ֵ��еĴ�
//�ж����
//
//solution:
//�����õݹ飬Ҳ������dp
//vector<vector<string> > dp;dp[i]��ʾi-n-1�����л�����ʽ
//dp[i] = for(str:dp[j+1]) && dict.count(str[i-j])
 
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<set>
#include<vector>

using namespace std;


class Solution {
public:
    vector<string> wordBreak(string s, set<string> &dict) {
    	int size = s.size();
        vector<vector<string> > res(size);
        for(int i=size-1;i>=0;i--){
        	for(int j=i;j<size;j++){
        		string str = s.substr(i,j-i+1);
        		if(dict.count(str)){
        			if(j == size-1){
        				res[i].push_back(str);
        			}else{
        				for(int k=0;k<res[j+1].size();k++){
        					res[i].push_back(str+" "+res[j+1][k]);
        				}
        			}
        		}
        	}
        }
        
        return res[0];
    }
};


int main(){
	Solution s;
	string str= "catsanddog";
	set<string> dict;
	dict.insert("cat");
	dict.insert("cats");
	dict.insert("and");
	dict.insert("sand");
	dict.insert("dog");
	
	vector<string> res = s.wordBreak(str,dict);
	for(int i=0;i<res.size();i++)
		cout<<res[i]<<endl;
}
