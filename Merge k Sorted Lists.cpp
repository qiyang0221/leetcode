//
//description:
//归并k个有序链表
//
//solution:
//这个跟归并两个有序链表不同，由于是多个链表，所以可以两两归并
//然后在merge，效率高很多 

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>

using namespace std;


struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *mergeKLists(vector<ListNode *> &lists){
		if(lists.size() <= 0)
			return NULL;
		
		return recur(lists,0,lists.size()-1);
	}
	
	ListNode * recur(vector<ListNode *> &lists,int start,int end){
		ListNode * mergeList = new ListNode(0);
		ListNode * list0,*list1;
		if(start == end)
			return lists[start];
		else if(end - start == 1){
			list0 = lists[start];
			list1 = lists[end];
			
		}else{
			list0 = recur(lists,start,(start+end)/2);
			list1 = recur(lists,(start+end)/2+1,end);
		}
		
		ListNode * newcur = mergeList;
		
		while(list0 != NULL && list1 != NULL){
			if(list0->val < list1->val){
				newcur->next = list0;
				newcur = list0;
				list0 = list0->next;
			}else{
				newcur->next = list1;
				newcur = list1;
				list1 = list1->next;
			}
		}
		if(list0 == NULL){
			newcur->next = list1;
		}
		if(list1 == NULL){
			newcur->next = list0;
		}
		
		return mergeList->next;
	}
	
    /*ListNode *mergeKLists(vector<ListNode *> &lists) {
    	int size = lists.size();
        ListNode * head = new ListNode(0);
        ListNode * newcur = head;
        
        
        bool flag = true;
        while(flag){
        	int index = -1;
        	flag = false;
        	if(lists.size() > 1){
        		for(int i=0;i<lists.size();i++){
	        		if(lists[i] != NULL){
	        			flag = true;
	        			if(index == -1)
	        				index = i;
	        			else{
	        				if(lists[i]->val < lists[index]->val)
	        					index = i;
	        			}
	        		}else{
	        			lists.erase(lists.begin()+i);
	        			i--;
	        		}
        		}
        		if(flag){
        			newcur->next = lists[index];
		        	newcur = lists[index];
		    		lists[index] = lists[index]->next;
		    		newcur->next = NULL;
        		}
        	}else{
        		break;
        	}
        	
    			
        }
        
        if(lists.size() > 0)
        	newcur->next = lists[0];
        
        head = head->next;
        return head;
    }*/
};

int main(){
	ListNode * ptr1_1 = new ListNode(1);//ListNode * ptr1_2 = new ListNode(6);ListNode * ptr1_3 = new ListNode(9);
	ListNode * ptr2_1 = new ListNode(1);ListNode * ptr2_2 = new ListNode(5);ListNode * ptr2_3 = new ListNode(7);
	ListNode * ptr3_1 = new ListNode(2);//ListNode * ptr3_2 = new ListNode(3);ListNode * ptr3_3 = new ListNode(3);
	
	ListNode * ptr4_1 = NULL;
	ListNode * ptr5_1 = NULL;
	
	//ptr1_1->next = ptr1_2;ptr1_2->next = ptr1_3;
	ptr2_1->next = ptr2_2;ptr2_2->next = ptr2_3;
	//ptr3_1->next = ptr3_2;ptr3_2->next = ptr3_3;
	
	vector<ListNode *> lists;
	//lists.push_back(ptr1_1);
	//lists.push_back(ptr2_1);
	//lists.push_back(ptr3_1);
	lists.push_back(ptr4_1);
	lists.push_back(ptr_1);
	
	Solution s;
	ListNode * head = s.mergeKLists(lists);
	while(head != NULL){
		cout<<head->val<<" ";
		head = head->next;
	}
	cout<<endl;
}
