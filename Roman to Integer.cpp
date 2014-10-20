//
//description:
//����������ת��������
//
//solution:
//������ĸ��������hash
//Ȼ�����ĸ��������ǰ�𽥼�
//���hash[i] < hash[i+1] res -= hash[i] ���� res += hash[i] 


#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
    	if(s.length() <= 0)
    		return 0;
        map<char,int> mp;
        mp['I'] = 1;
		mp['V'] = 5;
        mp['X'] = 10;
		mp['L'] = 50;
        mp['C'] = 100;
		mp['D'] = 500;
        mp['M'] = 1000;
        
        int i = s.length()-1;
        int res = mp[s[i--]];
        while(i>=0){
        	if(mp[s[i]] < mp[s[i+1]]){
        		res -= mp[s[i]];
        	}else
        		res += mp[s[i]];
        	i--;
        }
        
        return res;
    }
};

int main(){
	Solution s;
	
	cout<<s.romanToInt("XXX")<<endl;
}
