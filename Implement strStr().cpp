//
//description:
//实现strstr()，strstr表示查找字符串T在S中第一次出现的位置
//
//solution：
//kmp算法，首先找到next[]数组
//然后逐个查找是否匹配，找到后返回，复杂度是O(m+n) 

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;

class Solution {
public:
    char *strStr(char *haystack, char *needle) {
    	
    	if(haystack == NULL || needle == NULL)
    		return NULL;
    		
        int needle_len = strlen(needle);
        int needle_len = strlen(haystack);
        if(hay_len == 0)
    		return haystack;
    		
        if(hay_len < needle_len)
        	return NULL;
        
        int next[needle_len];
        getNext(needle,next);
        
        int i=0,j=0;
        while(i < hay_len){
        	if(j ==  -1 || haystack[i] == needle[j]){
        		i++,j++;
        	}else{
        		j = next[j];
        	}
        	if(j == needle_len)
        		return haystack+i-j;
        }
        
        return NULL;
    }
    
    void getNext(char * p, int *next){
    	int len = strlen(p);
    	int j= 0,k=-1;
    	next[0] = -1;
    	while(j < len){
    		if(k == -1 || p[j] == p[k]){
    			j++;
    			k++;
    			next[j] = k;
    		}else
    			k = next[k];
    	}
    }
};

int main(){
	char *A= "whatabigday";
	char *B = "big";
	
	Solution s;
	cout<<s.strStr("aa","a")<<endl;
	//char * C="ababa";
	//int next[5];
	//s.getNext(C,next);
}
