//
//description:
//�����һ�����ʵĳ���
//
//solution:
//ϸ���⣬����ǰ���пո����Ҫȥ��
//Ȼ���������ʿ�ʼ���㳤�� 

#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cstring>

using namespace std;

class Solution {
public:
	bool isletter(char x){
		if((x >= 'a' && x<='z') || (x >= 'A' && x <= 'Z'))
			return true;
		return false;
	}
    int lengthOfLastWord(const char *s) {
        if(s == NULL)
        	return 0;
        int len = strlen(s);
        if(len <= 0)
        	return 0;
        
        int i = 0,res = 0,count=0;
        while(i<len){
        	if(s[i] == ' '){
        		if(count > 0)
        			res = count;
        		count = 0;
        	}else{
        		count++;
        	}
        	i++;
        }
        if(count > 0)
        	res = count;
        
        return res;
    }
};

int main(){
	Solution s;
	cout<<s.lengthOfLastWord("dasf  adfa  ")<<endl;
}
