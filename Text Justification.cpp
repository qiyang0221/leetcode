//
//description:
//��һ���ַ�����ͬʱ��һ�����ȣ�һ�������¾���װ�¸�����ַ��������������٣�ʣ�µĿո���ȷ��䣬ǰ��ıȺ���Ķ�
//
//solution:
//ÿ��ͳ��һ�µ�ǰ���ʳ��ȣ���һ��֮���Ƿ񳬹�����
//vector<int>��¼һ��ÿ�ε��ʸ��� 
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        int size = words.size();
        vector<int> dis;
        vector<int> len_arr;
        int len = 0;
        int cnt =0;
        for(int i=0;i<size;i++){
        	if(!len){
        		len += words[i].size();
        		cnt++;
        	}else{
        		if(len+words[i].size()+cnt>L){
        			dis.push_back(cnt);
        			len_arr.push_back(len);
        			len=0;
        			cnt=0;
        			i--;
        		}else{
        			len+=words[i].size();
        			cnt++;
        		}
        	}
        }
        
        vector<string> res;
        int index=0;
        for(int i=0;i<dis.size();i++){
        	string str;
        	if(dis[i] == 1){
        		str+=words[index];
        		for(int i=str.size();i<L;i++)
        			str.push_back(' ');
        		index++;
        	}else{
        		int sp_cnt = (L-len_arr[i]) / (dis[i]-1);
	        	int sp_left = (L-len_arr[i]) % (dis[i]-1);
	        	for(int j=0;j<dis[i]-1;j++){
	        		str+=words[index];
	        		for(int j=0;j<sp_cnt;j++)
	        			str.push_back(' ');
	        		if(sp_left>0){
	        			str.push_back(' ');
	        			sp_left--;
	        		}
	        		index++;
	        	}
				str+=words[index++];	
        	}
        	res.push_back(str);
        }
        
        string str;
        for(;index<words.size()-1;index++){
        	str+=words[index];
        	str.push_back(' ');
        }
        str+=words[index];
        int str_len = str.size();
        for(int i=str_len;i<L;i++)
        	str.push_back(' ');
        res.push_back(str);
        
        return res;
    }
};

int main(){
	Solution s;
	vector<string> A;
	A.push_back("This");
	A.push_back("is");
	A.push_back("an");
	A.push_back("example");
	A.push_back("of");
	A.push_back("text");
	A.push_back("justification.");
	vector<string> res = s.fullJustify(A,16);
	
	for(int i=0;i<res.size();i++)
		cout<<res[i]<<endl;
}
