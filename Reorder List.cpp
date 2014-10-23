//
//description:
//将链表1 2 3 4 5按照 1 5 2 4 3排序
//
//solution:
//将链表中间阶段，将后半段逆序，然后再逐个链接即可
 
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
    void reorderList(ListNode *head) {
    	if(head == NULL || head->next == NULL || head->next->next == NULL)
    		return;
        ListNode * fir,*sec;
        fir = sec = head;
        while(fir != NULL && sec != NULL){
        	if(sec->next == NULL || sec->next->next == NULL)
        		break;
        	sec = sec->next->next;
        	fir = fir->next;
        }
        
        ListNode * cur = fir->next;
        fir->next = NULL; 
		ListNode * suc = cur->next; 
		cur->next = NULL;
        while(suc != NULL){
        	ListNode * ss = suc->next;
        	suc->next = cur;
        	cur = suc;
        	suc = ss;
        }
        
        ListNode * head1 = cur;
        
        ListNode * newhead = new ListNode(0);
        ListNode * tail = newhead;
        while(head != NULL && head1 != NULL){
        	tail->next = head;
        	head = head->next;
        	
        	tail = tail->next;
        	tail->next = head1;
        	head1 = head1->next;
        	
        	tail = tail->next;
        }
        if(head != NULL){
        	tail->next = head;
        	tail = tail->next;
        }
        
        tail->next = NULL;
        
        head = newhead->next;
    }
};

int main(){
	ListNode * node1 = new ListNode(1); 
	ListNode * node2 = new ListNode(2); 
	ListNode * node3 = new ListNode(3); 
	ListNode * node4 = new ListNode(4); 
	ListNode * node5 = new ListNode(5); 

	node1->next = node2;
	node2->next = node3;
	//node3->next = node4;
	//node4->next = node5;
	
	Solution s;
	s.reorderList(node1);
	ListNode * head = node1;
	while(head != NULL){
		cout<<head->val<<" ";
		head = head->next;
	} 
	cout<<endl;
} 
