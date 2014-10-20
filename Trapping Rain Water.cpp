//
//description:
//�кܶ෽������γ�ˮ�ۣ���ˮ
//�ʿ��Դ����ˮ
//
//solution:
//����һ�鵱ǰ�ڵ�������ֵ
//�ٴ��ұ߱����ұ����ֵ��ͬʱ���ϵ�ǰ���ˮ��
//O(n)ʱ��O(n)�ռ�
 
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<stack>
#include<queue>

using namespace std;

class Solution {
public:
	int trap(int A[],int n){
		if(n<=2)
			return 0;
		
		int lmh[n];
		int max = lmh[0] = A[0];
		for(int i=1;i<n;i++){
			lmh[i] = max;
			if(A[i] > max)
				max = A[i];
		}
		
		int vol=0;
		max = A[n-1];
		for(int i=n-2;i>0;i--){
			int height = lmh[i] < max ? lmh[i] : max;
			if(height > A[i])
				vol = vol + height - A[i];
			if(A[i] > max)
				max = A[i];
		}
		
		return vol;
	}
    /*int trap(int A[], int n) {
    	if(n == 0)
    		return 0;
        stack<int> s;
        int vol = 0;
        for(int i=0;i<n;i++){
        	if(s.empty()){
        		s.push(i);
        	}else{
        		if(A[i] <= A[s.top()]){
        			s.push(i);
        		}else{
        			int last;
        			while(!s.empty() && A[s.top()] < A[i]){
        				last = s.top();
        				s.pop();
        			}
        			int height;
        			if(s.empty())
        				height = A[last];
        			else
        				height = A[i];
        			int end = s.empty() ? last : s.top()+1;
        			for(int j=i-1;j>=end;j--){
        				vol = vol + height - A[j];
        				A[j] = height;
        			}
        			s.push(i);
        		}
        	}
        }
        
        return vol;
    }*/
};

int main(){

	int A[] = {4,2,0,3,2,4,3,4};
	
	Solution s;
	cout<<s.trap(A,8)<<endl;	
}
