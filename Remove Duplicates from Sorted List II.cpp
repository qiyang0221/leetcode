/*
/*question:
/*Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
/*For example,
/*Given 1->2->3->3->4->4->5, return 1->2->5.
/*Given 1->1->1->2->3, return 2->3.
/*
/*solution:
/*注意是sorted list，所以可以采用第二种方法，记录前驱和现在的地址就好了
/*不是sorted list采用map比较好，采用数组可能存在负数
*/

//code: 

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<map>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
    	map<int,int> m;
		
		ListNode * cur = head;
		while(cur != NULL){
			if(m[cur->val] == 0)
				m[cur->val] = 1;
			else
				m[cur->val]++;
			cur = cur->next;
		}
		
		cur = head;
		ListNode * pre = NULL;
		while(cur != NULL){
			if(m[cur->val] > 1){
				if(cur == head){
					cur = cur->next;
					head = cur;
				}else{
					pre->next = cur->next;
					cur = pre->next;
				}
			}else{
				pre = cur;
				cur = cur->next;
			}
		} 
		
		return head;
    }
    
    
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(head == NULL || head->next == NULL)
            return head;
            
        int value = head->val;
        ListNode * p = head->next, *pp = head;
        while(p!=NULL)
        {
            if(p->val == pp->val)
                pp->next = p->next;
            else
                pp=pp->next;
            p=p->next;
        }
        return head;
    }
};


//test:

int main(){
	ListNode * node1 = new ListNode(1);
	ListNode * node2 = new ListNode(1);
	ListNode * node3 = new ListNode(1);
	ListNode * node4 = new ListNode(2);
	ListNode * node5 = new ListNode(3);
	//ListNode * node6 = new ListNode(4);
	//ListNode * node7 = new ListNode(5);
	
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	//node5->next = node6;
	//node6->next = node7;
	
	
	Solution s;
	ListNode * head = s.deleteDuplicates(node1);
	ListNode * cur = head;
	while(cur != NULL){
		cout<<cur->val<<" ";
		cur = cur->next;
	}
	cout<<endl;
}
