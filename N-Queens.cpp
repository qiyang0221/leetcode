//
//description:
//多皇后问题
//
//solution:
//利用四个数组记录横向、纵向、左斜、右斜，避免重复
//然后递归求解
 

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
bool path[MAX][MAX];

class Solution {
public:
	vector<vector<string> >res;
	
	void dfs(int x,int n){
		if(x >= n){
			vector<string> solu;
			for(int i=0;i<n;i++){
				string rowstr;
				for(int j=0;j<n;j++){
					if(!path[i][j])
						rowstr.push_back('.');
					else
						rowstr.push_back('Q');
				}
				solu.push_back(rowstr);
			}
			res.push_back(solu);
			return;
		}
		
		for(int y=0;y<n;y++){
			if(!row[x] && !col[y] &&!left_bar[x+y] && !right_bar[x-y+n-1]){
				row[x] = col[y] = left_bar[x+y] =  right_bar[x-y+n-1] = true;
				path[x][y] = true;
				dfs(x+1,n);
				path[x][y] = false;
				row[x] = col[y] = left_bar[x+y] =  right_bar[x-y+n-1] = false;	
			}
		}
	}
	
    vector<vector<string> > solveNQueens(int n) {
        if(n==0)
        	return res;
        memset(row,0,sizeof(row));
        memset(col,0,sizeof(col));
        memset(left_bar,0,sizeof(left_bar));
        memset(right_bar,0,sizeof(right_bar));
        memset(path,0,sizeof(path));
        
        dfs(0,n);
        
        return res;
    }
};

int main(){
	Solution s;
	vector<vector<string> > res = s.solveNQueens(4);
	for(int i=0;i<res.size();i++){
		cout<<"]"<<endl;
		for(int j=0;j<res[i].size();j++)
			cout<<res[i][j]<<endl;
		cout<<"]"<<endl;
	}
}
