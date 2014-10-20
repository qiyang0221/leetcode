//
//description:
//��·��
//
//solution:
//�Զ���ʹ��stringֱ�Ӵ���
//
//������vector<string>ģ��ջ����·��������..�ų�,.����//��Ч����ĸ��ջ 
#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
    	if(path[path.length()-1] != '/')
    		path.push_back('/');
        string result;
        
        int i = 0;
        while(i < path.length()){
        	switch(path[i]){
        		case '/':
					if(result.empty())
						result.push_back('/');
					else{
						int res_len = result.length();
						if(result[res_len-1] == '.'){
							int dot_cnt = 0;
							int j;
							for(j=res_len-1;result[j] != '/' && j>=0;j--){
								if(result[j] == '.')
									dot_cnt++;
							}
							switch(dot_cnt){
								case 1:
									result.erase(j+1);
									break;
								case 2:
									result.erase(j+1);
									if(result.length() > 1){
										result.erase(result.length()-1);
										for(int k=result.length()-1;result[k] != '/' && k >0 ;k--)
											result.erase(k);
									}
									break;
								default:
									result.push_back('/');
							}
						}else{
							if(result[res_len-1] != '/')
								result.push_back('/');
						}
					}
					break;
				default:
					result.push_back(path[i]);
        	}
        	i++;
        }
        if(result.length() > 1 && result[result.length()-1] == '/')
        	result.erase(result.length()-1);
        	
        return result;
    }
};


int main(){
	Solution s;
	cout<<s.simplifyPath("/.")<<endl;
}
