//
//description:
//ÊýÊý
//1 11
//11 21
//21 1211
//1211 111221
//111221 312211


#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<sstream>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        vector<int> v;
        v.push_back(1);
        
        for(int i=2;i<=n;i++){
        	vector<int> vv;
        	int last = v[0];
        	int cnt = 1;
        	for(int j=1;j<v.size();j++){
        		if(last == v[j]){
        			cnt++;
        		}else{
        			vv.push_back(cnt);
        			vv.push_back(last);
        			cnt = 1;
        			last = v[j];
        		}
        	}
        	vv.push_back(cnt);
        	vv.push_back(last);
        	
        	v.clear();
        	for(int j=0;j<vv.size();j++)
        		v.push_back(vv[j]);
        }
        string res;
        for(int i=0;i<v.size();i++){
        	stringstream ss;
        	ss<<v[i];
        	string tmp;
        	ss>>tmp;
        	res+=tmp;
        }
        
        return res;
    }
};

int main(){
	Solution s;
	for(int i=1;i<10;i++)
		cout<<s.countAndSay(i)<<endl;
}
