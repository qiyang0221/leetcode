/*
/*question:
/*Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, 
/*with the colors in the order red, white and blue.
/*Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
/*
/*solution:
/*最简单的方法就是两路遍历，计算0,1,2的个数，然后覆盖原数组，也是题目提供的思路
/*如果要一遍遍历的话，应该联想到快排，如果当前遇到0，那么0就应该放在前面，如果遇到的是2就应该放到后面
/*所以用两个变量记录0和2应该放的位置
/*cur记录当前的位置，一般cur的位置要大于0的位置，小于2的位置
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
