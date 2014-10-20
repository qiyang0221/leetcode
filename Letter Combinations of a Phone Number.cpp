//
//description:
//手机上按键对应不同的字母，给出数字，求可能的字母组合
//
//solution:
//dfs
 
#include<cstdlib>
#include<cstdio>
#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

char mp[10][5] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
class Solution {
public:
    vector<string> letterCombinations(string digits) {
    	vector<string> res;
    	
        int len = digits.length();
        if(len <= 0){
        	res.push_back("");
        	return res;
        }
        	
        	
        string line;
        dfs(res,digits,line,0,len);
        
        return res;
    }
    
    void dfs(vector<string> &res, string digits,string line,int depth,int len){
    	if(depth >= len){
    		res.push_back(line);
    	}else{
    		int letter_len = strlen(mp[digits[depth]-'0']);
    		if(letter_len == 0){
    			dfs(res,digits,line,depth+1,len);
    		}else{
	    		for(int i=0;i<letter_len;i++){
	    			line += mp[digits[depth]-'0'][i];
	    			dfs(res,digits,line,depth+1,len);
	    			line.erase(line.end()-1);
	    		}
    		}
    	}
    }
};

int main(){
	Solution s;
	string str("2");
	vector<string> res = s.letterCombinations(str);
	
	for(int i=0;i<res.size();i++){
		cout<<res[i]<<endl;
	}
}
