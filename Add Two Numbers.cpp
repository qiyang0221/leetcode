//
//description:
//用链表表示两个数，求和
//solution:
//原链表就是逆序的，所以第一位表示低位，其他跟大整数乘法一样
 


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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode * head = new ListNode(0);
        ListNode * l3 = head;
        int carry = 0;
        while(l1 != NULL && l2 != NULL){
        	ListNode * tmp = new ListNode(0);
        	int val = l1->val + l2->val + carry;
        	tmp->val = val % 10;
        	carry = val / 10;
        	l3->next = tmp;
        	l3 = tmp;
        	l1 = l1->next;
        	l2 = l2->next;
        }
        
        while(l1 != NULL){
        	ListNode * tmp = new ListNode(0);
        	int val = l1->val + carry;
        	tmp->val = val % 10;
        	carry = val / 10;
        	l3->next = tmp;
        	l3 = tmp;
        	l1 = l1->next;
        }
        
        while(l2 != NULL){
        	ListNode * tmp = new ListNode(0);
        	int val = l2->val + carry;
        	tmp->val = val % 10;
        	carry = val / 10;
        	l3->next = tmp;
        	l3 = tmp;
        	l2 = l2->next;
        }
        
        if(carry > 0){
        	ListNode * tmp = new ListNode(carry);
        	l3->next = tmp;
        }
        
        return head->next;
    }
};


int main(){
	ListNode * l1_node1 = new ListNode(5);ListNode * l1_node2 = new ListNode(4);ListNode * l1_node3 = new ListNode(3);
	ListNode * l2_node1 = new ListNode(5);ListNode * l2_node2 = new ListNode(6);ListNode * l2_node3 = new ListNode(4);
	
	//l1_node1->next = l1_node2;
	//l1_node2->next = l1_node3;
	
	//l2_node1->next = l2_node2;
	//l2_node2->next = l2_node3;
	
	Solution s;
	ListNode * head = s.addTwoNumbers(l1_node1,l2_node1);
	while(head != NULL){
		cout<<head->val<<" ";
		head = head->next;
	}
}
