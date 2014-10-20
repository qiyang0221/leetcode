//
//description:
//将整数转化成罗马数字
//
//solution: 
//映射成1000 900 500 400 100 90 50 40 10 9 5 4 1
//      M    CM  D   CD  C   XC L  XL X  IX V IV I
//逐个减 

#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
    	string rom[4][10] = {"","I","II","III","IV","V","VI","VII","VIII","IX",
							"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC",
							"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM",
							"","M","MM","MMM","N","N","N","N","N","N"};
        string res;
        int carry = 0;
		while(num){
			int cur = num % 10;
			res = rom[carry][cur] + res;
			num = num / 10;
			carry++; 
		} 
		
		return res;
    }
};


int main(){
	Solution s;
	int num;
	cin>>num;
	while(num){
		cout<<s.intToRoman(num)<<endl;
		cin>>num;
	}
}
