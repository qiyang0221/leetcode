//
//description:
//add binary
//
//solution:
//�����Ƽӷ�����Ҫע���λ˳�򣬻�����Ҫ���ǽ�λ�����
//�����λ����ֵ����Ҫ�¼�һλ 



#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
    	string c;
    	
        int a_len = a.size();
        int b_len = b.size();
        
        if(a_len <= 0 || b_len <= 0)
        	return c;
        	
        int carry = 0;
        int i,j;
        
        for(i=a_len-1,j = b_len-1;i>=0 && j>=0;i--,j--){
        	int res = a[i] + b[j] - '0' - '0' + carry;
        	carry = res / 2;
        	res = res % 2;
        	c.insert(c.begin(),res+'0');
        }
        
        for(;i>=0;i--){
        	int res = a[i] + carry - '0';
        	carry = res / 2;
        	res = res % 2;
        	c.insert(c.begin(),res+'0');
        }
        
        for(;j>=0;j--){
        	int res = b[j] + carry - '0';
        	carry = res / 2;
        	res = res % 2;
        	c.insert(c.begin(),res+'0');
        }
        if(carry == 1){
        	c.insert(c.begin(),'1');
		} 
		
		return c;
    }
};

int main(){
	Solution s;
	cout<<s.addBinary("1","0")<<endl;
}
