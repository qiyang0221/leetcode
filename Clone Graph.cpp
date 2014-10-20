//
//description:
//��ȿ�¡ͼ
//
//solution:
//������Ҫע���һ��neighbors�ĵ㣬��Ҫnew������Ȼ�󷵻ظõ�ĵ�ַ
//���򿽱�����ȫ 

#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<set>
#include<vector>
#include<map>

 

using namespace std;


  struct UndirectedGraphNode {
      int label;
      vector<UndirectedGraphNode *> neighbors;
      UndirectedGraphNode(int x) : label(x) {};
  };

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == NULL)
        	return NULL;
        else{
        	map<UndirectedGraphNode*,UndirectedGraphNode*> mp;
        	dfs(node,mp);
        	return mp[node];
        }	
    }
    
    UndirectedGraphNode * dfs(UndirectedGraphNode *node,map<UndirectedGraphNode*,UndirectedGraphNode*> &mp){
    	if(mp.find(node) != mp.end())
    		return mp[node];
    	UndirectedGraphNode * node_cp = new UndirectedGraphNode(node->label);
    	mp[node] = node_cp;
    	for(int i=0;i<node->neighbors.size();i++){
    		node_cp->neighbors.push_back(dfs(node->neighbors[i],mp));
    	}
    	
    	return node_cp;
    }
};

int main(){
	
}
