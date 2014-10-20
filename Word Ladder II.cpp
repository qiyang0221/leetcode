#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<set>
#include<cstring>
#include<vector>
#include<map>
#include<queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string> > findLadders(string start, string end, set<string> &dict) {
    	set<string> current,next;    //当前层，下一层
		set<string> visited;
		map<string,vector<string> > father;
		
		bool found = false;
		
		set<string>::iterator iter;
		current.insert(start);
		while(!current.empty() && !found){
			for(iter=current.begin();iter!=current.end();iter++)
				visited.insert(*iter);
			for(iter=current.begin();iter!=current.end();iter++){
				for(int i=0;i<(*iter).size();i++){
					for(char c='a';c<='z';++c){
						string new_word = *iter;
						if(c == new_word[i]) continue;
						new_word[i] = c;
						
						if(new_word == end) found = true;
						
						if(visited.count(new_word) == 0 
							&& (dict.count(new_word) > 0) 
							|| new_word == end){
							next.insert(new_word);
							father[new_word].push_back(*iter);	
						}
					}
				}
			}
			current.clear();
			swap(current,next);
		}
		vector<vector<string> >result;
		
		if(found){
			vector<string> path;
			gen_path(father,path,start,end,result);
		}
		return result; 
    }
    
    void gen_path(map<string,vector<string> > &father,vector<string> &path,
					const string&start,const string &word,vector<vector<string> >&result){
		path.push_back(word);
		if(word == start){
			result.push_back(path);
			reverse(result.back().begin(),result.back().end());
		}else{
			vector<string>::iterator iter;
			for(iter=father[word].begin();iter!= father[word].end();iter++){
				gen_path(father,path,start,*iter,result);
			}
		}
		path.pop_back();	
	}
};


int main(){
	set<string> dict;
	dict.insert("hot");
	dict.insert("dot");
	dict.insert("dog");
	dict.insert("lot");
	dict.insert("log");
	
	string start = "hit";
	string end = "cog";
	
	Solution s;
	
	vector<vector<string> > res = s.findLadders(start,end,dict);
	
	for(int i=0;i<res.size();i++){
		for(int j=0;j<res[i].size();j++){
			cout<<res[i][j]<<" ";
		}
		cout<<endl;
	}
}
