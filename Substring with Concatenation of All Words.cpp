//
//description:
//�����ַ���S���Լ�һ��ȳ����ַ���L
//��������L�ַ���һ����ɵ��ִ�����ʼλ��
//
//solution:
//��map<string,int> need��¼ÿ��������ֵĴ���
//����ʾ��ʼλ�ã�Ȼ���ж�i-i+len*wordlen�Ƿ����
//���Ӷ�O(m*n)
 
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
	int wl;
	int cnt;
	
    vector<int> findSubstring(string S, vector<string> &L) {
    	vector<int> res;
    	
    	if(S.size() <= 0 || L.size() <= 0)
    		return res;
    		
    	map<string, int> mp;
    	for(int i=0;i<L.size();i++)
    		mp[L[i]]++;
    	
    	wl = L[0].size();
    	cnt = L.size();
    	int tot = wl * cnt;
    	
    	for(int i=0;i+tot<=S.size();i++){
    		if(helper(S,i,mp))
    			res.push_back(i);
    	}
    }
    
    bool helper(string S,int index, map<string,int> mp){
    	for(int i=0,j=index;i<cnt;i++,j+=wl){
    		string sub = S.substr(j,wl);
    		if(mp[sub] > 0){
    			mp[sub]--;
    		}else{
    			return false;
    		}
    	}
    	
    	return true;
    }
};

int main(){
	string S("lingmindraboofooowingdingbarrwingmonkeypoundcake");
	vector<string> v;
	
	v.push_back("fooo");
	v.push_back("barr");
	v.push_back("wing");
	v.push_back("ding");
	v.push_back("wing");
	
	
	Solution s;
	vector<int> res = s.findSubstring(S,v); 
	for(int i=0;i<res.size();i++)
		cout<<res[i]<<" ";
	cout<<endl;
}
