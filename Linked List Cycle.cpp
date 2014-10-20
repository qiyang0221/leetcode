//
//description:
//判断一个链表是否成环
//
//solution:
//设置两个指针，一个速度为1，一个为2，重合即有环
 
#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL)
        	return false;
        ListNode * gap1 = head->next;
        ListNode * gap2 = head->next;
        if(gap2 != NULL)
        	gap2 = gap2->next;
        else
        	return false;
        
        while(gap2 != NULL && gap1 != gap2){
        	gap1 = gap1->next;
        	gap2 = gap2->next;
        	if(gap2 != NULL)
        		gap2 = gap2->next;
        	else
        		return false;
        }
        
        if(gap1 == gap2)
        	return true;
        else
        	return false;
        
    }
};

int main(){
	Solution s;
	
	ListNode * node1 = new ListNode(3);
	ListNode * node2 = new ListNode(2);
	ListNode * node3 = new ListNode(0);
	ListNode * node4 = new ListNode(-4);
	
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node2;
	
	if(s.hasCycle(node1)){
		cout<<"true"<<endl;
	}else{
		cout<<"false"<<endl;
	}
}
