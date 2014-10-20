//
//description:
//归并两个链表
//
//solution:
//归并
 
#include<cstdio>
#include<cstdlib>
#include<iostream>

using namespace std;


struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode * head = new ListNode(0);
        ListNode * cur = head;
        while(l1 != NULL && l2 != NULL){
        	if(l1->val < l2->val){
        		cur->next = l1;
        		l1 = l1->next;
        		cur = cur->next;
        	}else{
        		cur->next = l2;
        		l2 = l2->next;
        		cur = cur->next;
        	}
        }
        
        while(l1 != NULL){
        	cur->next = l1;
        	l1 = l1->next;
        	cur = cur->next;
        }
        
        while(l2 != NULL){
        	cur->next = l2;
        	l2 = l2->next;
        	cur = cur->next;
        }
        
        cur->next = NULL;
        
        head = head->next;
        
        return head;
    }
};


int main(){
	/*ListNode * a1 = new ListNode(1);
	ListNode * a2 = new ListNode(1);
	ListNode * a3 = new ListNode(2);
	ListNode * a4 = new ListNode(5);
	
	a1->next = a2;
	a2->next = a3;
	a3->next = a4;*/
	ListNode * a1 = NULL;
	
	ListNode * b1 = new ListNode(2);
	ListNode * b2 = new ListNode(2);
	ListNode * b3 = new ListNode(3);
	ListNode * b4 = new ListNode(6);
	ListNode * b5 = new ListNode(7);
	
	b1->next = b2;
	b2->next = b3;
	b3->next = b4;
	b4->next = b5;
	
	
	Solution s;
	ListNode * head = s.mergeTwoLists(a1,b1);
	while(head != NULL){
		cout<<head->val<<" ";
		head = head->next;
	}
}
