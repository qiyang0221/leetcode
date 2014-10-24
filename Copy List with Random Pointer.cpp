//
//description:
//深拷贝随进访问链表
//
//solution：
//将拷贝点与原点形成一个新的列表
//这样ptr->next->random = ptr->random->next;
//第一遍修改random，不改prt->next
//第二遍将ptr分离出来
 
#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

struct RandomListNode {
  int label;
  RandomListNode *next, *random;
  RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};
 
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode * newhead = new RandomListNode(0);
        RandomListNode * cur = head;
        while(cur != NULL){
        	RandomListNode * tmp = cur->next;
        	RandomListNode * node = new RandomListNode(cur->label);
        	
        	cur->next = node;
        	node->next = tmp;
        	cur = tmp;
        }
        
        cur = head;
        while(cur != NULL){
        	if(cur->random != NULL){
        		cur->next->random = cur->random->next;
        	}else{
        		cur->next->random = NULL;
        	}
        	cur  = cur->next->next;
        }
        
        cur = head;
        RandomListNode * tail = newhead;
        while(cur != NULL){
        	tail->next = cur->next;
        	tail = tail->next;
        	
        	cur->next = cur->next->next;
        	cur = cur->next;
        }
        
        tail->next = NULL;
        return newhead->next;
    }
};

int main(){
	RandomListNode * node1 = new RandomListNode(1);
	RandomListNode * node2 = new RandomListNode(2);
	RandomListNode * node3 = new RandomListNode(3);
	RandomListNode * node4 = new RandomListNode(4);
	RandomListNode * node5 = new RandomListNode(5);
	
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	
	node1->random = node3;
	node2->random = node5;
	node3->random = NULL;
	node4->random = node1;
	node5->random = node2;
	
	Solution s;
	RandomListNode * head =  s.copyRandomList(node1);
	while(head != NULL){
		cout<<head->label<<" ";
		if(head->random != NULL)
			cout<<head->random->label<<endl;
		else
			cout<<"null"<<endl;
		head = head->next;
	}
	
	cout<<"******************"<<endl;
	RandomListNode * cur = node1;
	while(cur != NULL){
		cout<<cur->label<<" ";
		if(cur->random != NULL)
			cout<<cur->random->label<<endl;
		else
			cout<<"null"<<endl;
		cur = cur->next;
	}
} 
