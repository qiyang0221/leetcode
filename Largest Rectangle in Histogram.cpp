/*
/*question:
/*Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, 
/*find the area of largest rectangle in the histogram.
/*Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].
/*The largest rectangle is shown in the shaded area, which has area = 10 unit.
/*For example,
/*Given height = [2,1,5,6,2,3],
/*return 10.
/*
/*solution:
/*�����Ŀ��򵥵ķ������ǣ��Ե�ǰֱ��ͼΪ�߶ȣ�������������չ����ȡ��ǰ�߶ȵ�����ȣ��Ϳ�����ǰ�߶ȵľ��ε�������
/*���Ӷ���O(n^2)
/*������뷨���õ���ջ���������еĸ߶ȣ������ǰ�ĸ߶�С��ջ�ڸ߶ȣ���ô��pop��top�����������ĸ߶�
/*ջ��˼�����������һ�����ҵ�С�ڵ�ǰջ�߶ȵı���ʵ�����ҵ����ұߵ��յ㣬����ߵ��յ����ջ�µ�λ�ã����Ϊ�գ���ô��ߵ��յ�������
/*����˼·�ĸ��Ӷ�С��O(n^2)����Ϊÿ�β���Ҫ��ǰֱ��ͼ�����ұ߽磬�����ұ߽�ĸ��Ӷ�Ϊ1
*/

//code: 

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<stack>
#include<vector>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        stack<int> s;
        height.push_back(0);
        int size = height.size();
        if(size == 0)
        	return 0;
        int max_area = 0;
        for(int i=0;i<size;i++){
        	if(s.empty() || height[i] >= height[s.top()]){
        		s.push(i);
        	}else{
    			int index = s.top();
    			s.pop();
    			int width = s.empty() ? i : (i-s.top() - 1);
    			int area = width * height[index];
    			if(area > max_area)
    				max_area = area;
        		i--;
        	}
        	
        }
        
        return max_area;
    }
};

using namespace std;

//test:
int main(){
	vector<int> v;
	v.push_back(4);
	v.push_back(2);
	v.push_back(0);
	v.push_back(3);
	v.push_back(2);
	v.push_back(5);
	
	Solution s;
	cout<<s.largestRectangleArea(v)<<endl;
}
