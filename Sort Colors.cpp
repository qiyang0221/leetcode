/*
/*question:
/*Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, 
/*with the colors in the order red, white and blue.
/*Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
/*
/*solution:
/*��򵥵ķ���������·����������0,1,2�ĸ�����Ȼ�󸲸�ԭ���飬Ҳ����Ŀ�ṩ��˼·
/*���Ҫһ������Ļ���Ӧ�����뵽���ţ������ǰ����0����ô0��Ӧ�÷���ǰ�棬�����������2��Ӧ�÷ŵ�����
/*����������������¼0��2Ӧ�÷ŵ�λ��
/*cur��¼��ǰ��λ�ã�һ��cur��λ��Ҫ����0��λ�ã�С��2��λ��
*/

//code: 

#include<cstdio>
#include<cstdlib>
#include<iostream>

using namespace std;

class Solution {
public:
	void swap(int A[],int i,int j){
		int tmp = A[j];
		A[j] = A[i];
		A[i] = tmp;
	}
    void sortColors(int A[], int n) {
    	if(n<=1)
    		return;
    	int z=0,w=n-1;
    	int cur = 0;
    	while(cur<=w){
    		if(A[cur] == 0){
    			if(cur > z){
    				swap(A,z,cur);
    				z++;
    			}else{
    				cur++;
    				z++;
    			}
    		}else if(A[cur] == 2){
				if(cur<w){
					swap(A,cur,w);
					w--;
				}
				else
					return;
			}else
				cur++;
    	}
    	
    }
};

int main(){
	int A[] = {1,0};
	Solution s;
	s.sortColors(A,2);
}
