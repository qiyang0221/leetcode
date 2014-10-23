//
//description:
//用O(nlog(n))辅助度排序
//
//solution:
//利用quick_sort的思路，将链表分为两块，然后再归并
 
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
    ListNode *sortList(ListNode *head) {
    	return  qsortList(head,NULL);
    }
    
    ListNode * qsortList(ListNode * start,ListNode * end){
    	if(start == NULL || start == end)
    		return NULL;
    	if(start->next == end || start->next == NULL){
    		start->next = NULL;
    		return start;
    	}
    	
    	ListNode * one = start,*two = start;
    	while(two != end){
    		if(two->next == end){
    			two = two->next;
    			break;
    		}
    		if(two->next->next == end){
    			two = two->next->next;
    			break;
    		}
			two = two->next->next;
			one = one->next;
    	}
    	
    	ListNode * mid = one->next;
    	ListNode * fir = qsortList(start,mid);
    	ListNode * sec = qsortList(mid,end);
    	
    	
    	ListNode * head = new ListNode(0);
    	ListNode * tail = head;
    	while(fir != NULL && sec != NULL){
    		if(fir->val < sec->val){
    			tail->next = fir;
    			fir = fir->next;
    		}else{
    			tail->next = sec;
    			sec = sec->next;
    		}
    		tail = tail->next;
    	}
    	
    	while(fir != NULL){
    		tail->next = fir;
    		fir = fir->next;
    		tail = tail->next;
    	}
    	
    	while(sec != NULL){
    		tail->next = sec;
    		sec = sec->next;
    		tail = tail->next;
    	}
    	tail->next = NULL;
    	
    	return head->next;
    }
    
};


int main(){
	ListNode * node1 = new ListNode(4);
	ListNode * node2 = new ListNode(5);
	ListNode * node3 = new ListNode(2);
	ListNode * node4 = new ListNode(3);
	ListNode * node5 = new ListNode(6);
	ListNode * node6 = new ListNode(9);
	ListNode * node7 = new ListNode(1);
	
	node1->next = node2;
	//node2->next = node3;
	//node3->next = node4;
	//node4->next = node5;
	//node5->next = node6;
	//node6->next = node7;
	
	Solution s;
	ListNode * head = s.sortList(node1);
	while(head != NULL){
		cout<<head->val<<" ";
		head = head->next;
	}
	cout<<endl;
}
