//
//description:
//题目的意思是给你一组数，让你求出重复出现的数（由一些相同字母组成即可），只出现一次不计 
//solution:
//利用map来判断数是否重复，同时map<string,int>后面int记录数第一次出现的index位置
//由于map[string]不存在时等于0，所以需要插入一个数，保证索引从1开始 


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
