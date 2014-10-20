//
//description:
//删除从结尾数第n个节点
//
//solution:
//两个指针，一个先走n步，另一个从0开始
//当第一个走到结果出，删除第二个节点即可
 
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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
    	if(head == NULL)
    		return head;
    		
        ListNode * cur = head;
        ListNode * ncur = head;
        ListNode * last = NULL;
        int i = 0;
        int tot = 0;
        while(ncur){
        	int j;
        	for(j=0;j<n;j++){
        		if(ncur->next != NULL){
        			ncur = ncur->next;
        			tot++;
        		}else
        			break;
        	}
        	if(j < n){
        		int end = tot - n;
        		while(i <= end){
        			last = cur;
        			cur = cur->next;
        			i++;
        		}
        		if(last == NULL){
        			head = head->next;
        		}else{
        			last->next = cur->next;
        		}
        		break;
        	}else{
        		last = cur;
        		cur = cur->next;
        		i++;
        	}
        	
        }
        
        return head;
    }
};

int main(){
	Solution s;
	
	ListNode * node1 = new ListNode(1);
	ListNode * node2 = new ListNode(2);
	ListNode * node3 = new ListNode(3);
	ListNode * node4 = new ListNode(4);
	ListNode * node5 = new ListNode(5);
	ListNode * node6 = NULL;
	
	node1->next = node2;
	//node2->next = node3;
	//node3->next = node4;
	//node4->next = node5;
	
	ListNode * head = s.removeNthFromEnd(node1,1);
	while(head != NULL){
		cout<<head->val<<" ";
		head = head->next;
	}
}
