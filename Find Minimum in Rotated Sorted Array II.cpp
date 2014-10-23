//
//description:
//��һ����ת�����������С�����������ظ�
//
//solution:
//���ö��ֵķ�������ϸ������
//������Ŀ������ö��ֵĻ���������ϸ����mid�Ƿ�Ҫ�Ӽ�1����Ϊ�����׾���������С��
//���иտ�ʼ����Ҫ�ж�l��r�Ĵ�С�����lС��r��ֱ�ӷ��ؽ���ͺ�
 
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int> &num) {
        int size = num.size();
        if(size == 1 || num[0] < num[size-1])
        	return num[0];
        int l=0,r=size-1;
        while(l < r){
        	if(num[l] < num[r])
        		return num[l];
        	int mid = (l+r)/2;
        	if(num[mid] < num[r])
        		r = mid;
        	else if(num[mid] > num[r]){
        		l = mid+1;
        	}else{
        		++l;
        		--r;
        	}
        }
        
        return num[(l+r)/2];
    }
};
int main(){
	
	vector<int> num;
	num.push_back(10);
	num.push_back(10);
	num.push_back(10);
	num.push_back(10);
	num.push_back(1);
		
	Solution s;
	cout<<s.findMin(num)<<endl;
}


