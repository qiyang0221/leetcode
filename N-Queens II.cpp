//
//description:
//求有多少种N-queens解法
//
//solution:
//深搜，算法复杂度O(n!),空间复杂度O(n) 
 
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<cstring>

using namespace std;
const int MAX = 20;
bool row[MAX];
bool col[MAX];
bool left_bar[2*MAX];
bool right_bar[2*MAX];

class Solution {
public:
	int tot;
	
	void dfs(int x,int n){
		if(x >= n){
			tot++;
			return;
		}
		
		for(int y=0;y<n;y++){
			if(!row[x] && !col[y] &&!left_bar[x+y] && !right_bar[x-y+n-1]){
				row[x] = col[y] = left_bar[x+y] =  right_bar[x-y+n-1] = true;
				dfs(x+1,n);
				row[x] = col[y] = left_bar[x+y] =  right_bar[x-y+n-1] = false;	
			}
		}
	}
	
    int totalNQueens(int n) {
        if(n==0)
        	return 0;
        memset(row,0,sizeof(row));
        memset(col,0,sizeof(col));
        memset(left_bar,0,sizeof(left_bar));
        memset(right_bar,0,sizeof(right_bar));
        
        tot = 0;
        dfs(0,n);
        
        return tot;
    }
};

int main(){
	Solution s;
	cout<<s.totalNQueens(4)<<endl;
}
