//
//description:
//����һ�����飬��ʾһ����y��ƽ�е��ߣ���ֵ��ʾ�߶�
//��������i,j����Ȧ����ˮ
//
//solution:
//ȡ��������i,j���height[i]<height[j]����ôֻ��height[i]�����ƶ���
//���������ƶ�height[j]�����Խ��ԽС
//i,j�ֱ�Ϊ0��size-1 

#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
    	int max_area = 0;
    	int i = 0,j = height.size()-1;
    	while(i<j){
    		int area;
    		if(height[i] < height[j]){
    			area = height[i] * (j-i);
    			i++;
    		}else{
    			area = height[j] * (j-i);
    			j--;
    		}
    		if(area > max_area)
    			max_area = area;
    	}
    	
    	return max_area;
    }
};

int main(){
	vector<int> height;
	/*height.push_back(1);
	height.push_back(2);
	height.push_back(1);
	height.push_back(0);
	height.push_back(2);
	height.push_back(1);
	height.push_back(0);
	height.push_back(1);
	height.push_back(3);
	height.push_back(2);
	height.push_back(1);
	height.push_back(2);
	height.push_back(3);*/
	
	Solution s;
	cout<<s.maxArea(height)<<endl;
}
