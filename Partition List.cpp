/*
/*question:
/*Given a linked list and a value x, partition it such that all nodes 
/*less than x come before nodes greater than or equal to x.
/*You should preserve the original relative order of the nodes 
/*in each of the two partitions.
/*For example,
/*Given 1->4->3->2->5->2 and x = 3,
/*return 1->2->2->4->3->5.
/*
/*solution:
/*这道题的trick需要保持原来的顺序 
*/ 

//code:

 
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
    ListNode *partition(ListNode *head, int x) {
    	
    	if(head == NULL)
    		return head;
        ListNode * mid = new ListNode(0);
		ListNode * tail = mid;
		ListNode * newhead = NULL;
		ListNode * pre_mid = NULL;
		ListNode * tail_next = NULL;
        
        ListNode * cur = head;
        ListNode * cur_next = NULL;
        
        while(cur != NULL){
        	cur_next = cur->next;
        	if(cur->val >= x){
        		tail->next = cur;
        		tail = cur;
        		tail->next = NULL;
        	}else{
        		if(pre_mid == NULL){
        			cur->next = mid;
        			pre_mid = cur;
        			newhead = cur;
        		}else{
        			pre_mid->next = cur;
        			cur->next = mid;
        			pre_mid = cur;
        		}
        	}
        	cur = cur_next;
        }
        
        if(pre_mid == NULL){
        	return mid->next;
        }else{
        	pre_mid->next = mid->next;
        }
        
        
        return newhead;
    }
};

//test:

int main(){
	//ListNode * node1 = NULL;
	ListNode * node1 = new ListNode(1);
	ListNode * node2 = new ListNode(2);
	/*ListNode * node3 = new ListNode(3);
	ListNode * node4 = new ListNode(2);
	ListNode * node5 = new ListNode(5);
	ListNode * node6 = new ListNode(2);*/
	
	node1->next = node2;
	/*node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = node6;*/
	
	Solution s;
	ListNode * head = s.partition(node1,0);
	ListNode * cur = head;
	while(cur != NULL){
		cout<<cur->val<<" ";
		cur = cur->next;
	}
	cout<<endl;
}
