//
//description:
//插入排序数组
//
//solution:
//插入排序
 
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
    ListNode *insertionSortList(ListNode *head) {
        ListNode * newhead = new ListNode(0);
        while(head != NULL){
        	ListNode * tmp = head->next;
        	ListNode * cur = newhead->next;
        	ListNode * pre = newhead;
        	while(cur != NULL){
        		if(cur->val > head->val)
        			break;
        		pre = cur;
        		cur = cur->next;
        	}
        	
        	pre->next = head;
        	head->next = cur;
        	
        	head = tmp;
        }
        
        return newhead->next;
    }
};

int main(){
	ListNode * node1 = new ListNode(4);
	ListNode * node2 = new ListNode(3);
	ListNode * node3 = new ListNode(1);
	ListNode * node4 = new ListNode(5);
	ListNode * node5 = new ListNode(7);
	
	node1->next = node2;
	//node2->next = node3;
	//node3->next = node4;
	//node4->next = node5;
	
	Solution s;
	ListNode * head = s.insertionSortList(node1);
	while(head != NULL){
		cout<<head->val<<" ";
		head = head->next;
	}
	cout<<endl;
}
