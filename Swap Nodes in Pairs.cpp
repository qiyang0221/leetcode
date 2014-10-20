//
//description:
//交换链表的相邻两个节点
//
//solution:
//如题
 
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
    ListNode *swapPairs(ListNode *head) {
    	if(head == NULL)
    		return head;
		ListNode * fhead = new ListNode(0);
		fhead->next = head;
		ListNode * pre = fhead;
		ListNode * cur = head;
		ListNode * next = head->next;
		
		while(cur != NULL && next != NULL){
			cur->next = next->next;
			pre->next = next;
			next->next = cur;
			if(cur->next != NULL && cur->next->next != NULL){
				pre = cur;
				cur = cur->next;
				next = cur->next;
			}else{
				break;
			}
		}
		
		return fhead->next;    
    }
};

int main(){
	Solution s;
	
	ListNode * node1 = new ListNode(1);
	ListNode * node2 = new ListNode(2);
	ListNode * node3 = new ListNode(3);
	ListNode * node4 = new ListNode(4);
	ListNode * node5 = new ListNode(5);
	
	//node1->next = node2;
	//node2->next = node3;
	//node3->next = node4;
	//node4->next = node5;
	
	ListNode * head = s.swapPairs(node1);
	while(head != NULL){
		cout<<head->val<<" ";
		head = head->next;
	}
	cout<<endl;
}
