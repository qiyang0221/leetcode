//
//description:
//����n���ܲ������ٲ�ͬ�ĺϷ����ţ�ͬʱ��¼����
//
//solution:
//��������f(n)=f(0)f(n-1)+f(1)(n-2)+����+f(n-1)f(0)
//����ݹ�ͺ��ˣ���һ��left��¼ʹ�õ������Ÿ�������һ��right��¼�����Ÿ���
//rightʼ��С�ڵ���left
//��left==sizeʱ������ʣ�µ�right 


#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<stack>
#include<vector>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if(n <= 0)
        	return res;
        string line;
        recur(res,line,0,0,n);
        
        return res;
    }
    
    void recur(vector<string> &res,string line,int left,int right,int n){
    	line += "(";
    	if(left == n-1){
    		while(right <= left){
    			line+=")";
    			right++;
    		}
    		res.push_back(line);
    	}else{
    		left++;
    		for(int i=0;i<=left-right;i++){
    			string tmp(i,')');
    			recur(res,line+tmp,left,right+i,n);
    		}
    	}
    }
};

int main(){
	Solution s;
	vector<string> res = s.generateParenthesis(2);
	for(int i=0;i<res.size();i++)
		cout<<res[i]<<endl;
}
