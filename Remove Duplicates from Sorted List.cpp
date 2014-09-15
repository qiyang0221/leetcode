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
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode * cur = head;
        if(cur == NULL)
        	return head;
        ListNode * next = cur->next;
        if(next == NULL)
        	return head;
        	
        while(cur && next){
        	if(cur->val == next->val){
        		cur->next = next->next;
        		next = next->next;
        	}else{
        		cur = next;
        		next = next->next;
        	}
        }
        
        return head;
    }
};


int main(){
	ListNode * node1 = new ListNode(1);
	ListNode * node2 = new ListNode(1);
	ListNode * node3 = new ListNode(2);
	//ListNode * node4 = new ListNode(3);
	//ListNode * node5 = new ListNode(3);
	
	node1->next = node2;
	node2->next = node3;
	//node3->next = node4;
	//node4->next = node5;
	
	Solution s;
	ListNode * head = s.deleteDuplicates(node1);
	while(head){
		cout<<head->val<<" ";
		head = head->next;
	}
}
