//
//descrition:
//���ַ���ת��������
//
//solution:
//�ַ���ǰ������пո�
//������С��һ�����������С����С������������
//��Ҫ����������
 
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;

typedef long long ll;

class Solution {
public:
    int atoi(const char *str) {
        ll res = 0;
        
        bool flag = true;
        
        int i = 0;
        for(;str[i] == ' ';i++);
        
        if(str[i] == '-'){
        	flag = false;
        	i++;
        }else if(str[i] == '+'){
        	i++;
        }
        
        int len = strlen(str);
        while(i<len){
        	if(str[i]>= '0' && str[i] <= '9'){
        		res = res * 10 + str[i] - '0';
        	}else
        		break;
        	i++;
        }
        
        if(!flag){
        	res = -res;
        	if(res < -2147483648)
        		res = -2147483648;
        }
        else{
        	if(res > 0x7fffffff)
        		res = 0x7fffffff;
        }
        
        return res;
    }
};

int main(){
	
	Solution s;
	
	cout<<s.atoi("-2147483649")<<endl;
}
