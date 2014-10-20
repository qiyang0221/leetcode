//
//description:
//����Խ��ַ����ֽ�ɻ���������������
//
//solution:
//���Բ���dfs���жϵ�ǰ�ǻ�������Ȼ��ݹ�ʣ���ִ��ǻ����������
//���Ӷ�2^n
//�����ö�̬�滮��p[i][j]�ж�i-j�Ƿ��ǻ�����
//Ȼ����vector<vector<string>>��¼s[i-n-1]���������
//����ÿһ��i������j-n-1���p[i][j]��������ôp[i][j]��vector<j+1>������� 
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<cstring>

using namespace std;

class Solution {
public:
	
	vector<vector<string> > partition(string s){
    	const int n = s.size();
    	bool p[n][n];
    	memset(p,0,sizeof(p));
    	
    	for(int i=n-1;i>=0;--i){
    		for(int j=i;j<n;++j){
    			p[i][j] = s[i] == s[j] && ((j-i < 2) || p[i+1][j-1]);
    		} 
    	}
    	for(int i=0;i<n;i++){
    		for(int j=0;j<n;j++)
    			if(p[i][j])
    				cout<<"1 ";
    			else
    				cout<<"0 ";
    		cout<<endl;
    	}
    	vector<vector<string> > sub_plains[n];
    	for(int i=n-1;i>=0;--i){
    		for(int j=i;j<n;++j){
    			if(p[i][j]){
    				string palindrome = s.substr(i,j-i+1);
    				cout<<palindrome<<endl;
    				if(j+1<n){
    					for(int k=0;k<sub_plains[j+1].size();k++){
    						vector<string> v = sub_plains[j+1][k];
    						v.insert(v.begin(),palindrome);
    						sub_plains[i].push_back(v);
    					}
    				}else{
    					vector<string> v;
    					v.push_back(palindrome);
    					sub_plains[i].push_back(v);
    				}
    			}
    		}
    	}
    	
    	return sub_plains[0];
    }
    
	/*bool isPalidrome(string str){
		int len = str.length();
		int i,j;
		for(i=0,j=len-1;i<j && str[i] == str[j];i++,j--);
		
		if(i>=j)
			return true;
		else
			return false;
	}
	
    vector<vector<string> > partition(string s) {
        vector<vector<string> > res;
        int len = s.length();
        if(len == 1){
        	vector<string> line;
        	line.push_back(s);
        	res.push_back(line);
        }else{
        	for(int i=1;i<=s.length();i++){
	        	string str = s.substr(0,i);
	        	if(isPalidrome(str)){
	        		if(str == s){
	        			vector<string> line;
	        			line.push_back(s);
	        			res.push_back(line);
	        		}else{
	        			vector<vector<string> > sub = partition(s.substr(i));
		        		for(int i=0;i<sub.size();i++){
		        			vector<string> line = sub[i];
		        			line.insert(line.begin(),str);
		        			res.push_back(line);
		        		}
	        		}	
	        	}
        	}
        }
        
        return res;
    }*/
};

int main(){
	Solution s;
	vector<vector<string> > res = s.partition("aaab");
	for(int i=0;i<res.size();i++){
		for(int j=0;j<res[i].size();j++)
			cout<<res[i][j]<<" ";
		cout<<endl;
	}
}
