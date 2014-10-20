//
//description:
//最长公共前缀
//
//solution:
//逐个判断是否相等，直到有一个不相等 


#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if(strs.size() <= 0)
        	return "";
        bool exit = false;
        int j=0;
        while(true){
        	char tmp;
        	if(j < strs[0].size())
        		tmp = strs[0][j];
        	else
        		break;
        	int i;
        	for(i=1;i<strs.size();i++){
        		if(j >= strs[i].size() || strs[i][j] != tmp)
        			break;
        	}
        	
        	if(i != strs.size())
        		break;
        	j++;
        }
        
        return strs[0].substr(0,j); 
    }
};


int main(){
	vector<string> strs;
	
	string str1("");
	string str2("ege");
	
	strs.push_back(str1);
	//strs.push_back(str2);
	
	Solution s;
	cout<<s.longestCommonPrefix(strs)<<endl;
}
