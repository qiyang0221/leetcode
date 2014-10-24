//
//description:
//
//solution:
//�����Ŀ��hash_map��¼ÿ��������Χ�����Ѷ˳��ֵĴ���
//������һ�����ݵ�ʱ�򣬿��ܰѳ��ȱ��len = hash[left] + hash[right] + 1
//Ȼ���ڸ������ҷ�Χ���ȵĴ�С����
//û���ҵ��ǹ������㷨
 
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
    	int size = num.size();
    	int max = 0;
    	map<int,int> mp;
        for(int i=0;i<size;i++){
        	if(mp[num[i]] == 0){	
	    		int len = mp[num[i]-1] + mp[num[i]+1]+1;
	    		if(len > max)
					max = len;
				int left = num[i] - mp[num[i] -1 ];
				int right = num[i] + mp[num[i] + 1];
				mp[num[i]] = len; 
				mp[left] = len;
				mp[right] = len; 
			}
        }
        
        return max;
    }
};

int main(){
	vector<int> num;
	int len;
	scanf("%d",&len);
	for(int i=0;i<len;i++){
		int val;
		scanf("%d",&val);
		num.push_back(val);
	}
	
	
	Solution s;
	
	cout<<s.longestConsecutive(num)<<endl;
	/*sort(num.begin(),num.end());
	for(int i=0;i<len;i++)
		cout<<num[i]<<" ";
	cout<<endl;*/
}
