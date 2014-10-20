//
//description:
//按照K分组进行反转
//
//solution:
//头尾指针即可
 
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
    ListNode *reverseKGroup(ListNode *head, int k) {
    	if(k == 0 || head == NULL)
    		return head;
    	ListNode * cur = head;
    	int len = 0;
    	while(cur != NULL){
    		len++;
    		cur = cur->next;
    	}
    	
    	if(k > len)
    		return head;
    	ListNode * fhead = new ListNode(0);
    	ListNode * mid = fhead;
    	ListNode * tail;
        cur = head;
        
        for(int i = k;i<=len;i+=k){
        	tail = NULL;
        	for(int j=0;j<k;j++){
	        	ListNode * tmp = cur->next;
	        	ListNode * next = mid->next;
	        	if(tail == NULL)
	        		tail = cur;
	        	mid->next = cur;
	        	cur->next = next;
	        	cur = tmp;
	        }
	        mid = tail;
        }
        if(tail != NULL)
	        tail->next = cur;
            
        return fhead->next;
    }
    
};

int main(){
	ListNode * node1 = new ListNode(1);
	ListNode * node2 = new ListNode(2);
	ListNode * node3 = new ListNode(3);
	ListNode * node4 = new ListNode(4);
	ListNode * node5 = new ListNode(5);
	
	//node1->next = node2;
	//node2->next = node3;
	//node3->next = node4;
	//node4->next = node5;
	ListNode * tmp = NULL;
	Solution s;
	ListNode * head = s.reverseKGroup(node1,1);
	while(head != NULL){
		cout<<head->val<<" ";
		head = head->next;
	}
	cout<<endl;
}
