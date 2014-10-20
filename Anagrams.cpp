//
//description:
//��Ŀ����˼�Ǹ���һ��������������ظ����ֵ�������һЩ��ͬ��ĸ��ɼ��ɣ���ֻ����һ�β��� 
//solution:
//����map���ж����Ƿ��ظ���ͬʱmap<string,int>����int��¼����һ�γ��ֵ�indexλ��
//����map[string]������ʱ����0��������Ҫ����һ��������֤������1��ʼ 


#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
    	vector<string> res;
    	map<string,int> mp;
    	strs.insert(strs.begin(),"");
    	for(int i=1;i<strs.size();i++){
    		string  cur = strs[i];
    		sort(cur.begin(),cur.end());
    		if(mp[cur] == 0){
    			mp[cur] = i;
    		}else if(mp[cur] > 0){
    			res.push_back(strs[mp[cur]]);
    			res.push_back(strs[i]);
    			mp[cur] = -1;
    		}else {
    			res.push_back(strs[i]);
    		}
    	}
        
        return res;
    }
};

int main(){
	vector<string> strs;
	strs.push_back("eat");
	strs.push_back("ate");
	strs.push_back("foo");
	strs.push_back("foe");
	
	Solution s;
	vector<string> res = s.anagrams(strs);
	
	for(int i=0;i<res.size();i++)
		cout<<res[i]<<endl;
}
