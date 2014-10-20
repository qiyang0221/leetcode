//
//description:
//�������ڵ�k��λ����ת
//
//solution:
//ע�⣬k���ܴ��������ȣ�������������Ⱥ�����
//Ȼ������µĵ�k��λ�ü���
 
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
    ListNode *rotateRight(ListNode *head, int k) {
    	
    	if(head == NULL)
    		return head;
    		
        ListNode * tail = head;
        int count = 0;
        while(tail->next != NULL){
        	tail = tail->next;
        	count++;
        }
        
        count++;
        
        int kv = count - (k % count);
        
        for(int i=0;i<kv;i++){
        	tail->next = head;
        	tail = tail->next;
        	head = head->next;
        	tail->next = NULL;
        }
        
        return head;
    }
};


int main(){
	ListNode * node1 = new ListNode(1);
	ListNode * node2 = new ListNode(3);
	ListNode * node3 = new ListNode(4);
	ListNode * node4 = new ListNode(5);
	
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	
	Solution s;
	ListNode * head = s.rotateRight(node1,1);
	while(head != NULL){
		cout<<head->val<<" ";
		head = head->next;
	}
	cout<<endl;
}
