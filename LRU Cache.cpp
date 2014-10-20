//
//description:
//最少访问，最先推出，最近访问，最先被查找到
//
//solution:
//双向链表，记录顺序，map记录key value 
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<queue>
#include<map>

using namespace std;

struct CacheNode{
	int key;
	CacheNode * prev;
	CacheNode * next;
	CacheNode(int val):key(val),prev(NULL),next(NULL){
	}
};

class LRUCache{
public:
	int size;
	int capacity;
	map<int,int> mp;
	CacheNode * head;
	CacheNode * tail;
    LRUCache(int capacity) {
    	this->capacity = capacity;
    	size = 0;
    	head = new CacheNode(0);
    	tail = new CacheNode(0);
    	head->next = tail;
    	tail->prev = head;
    }
    
    int get(int key) {
        if(mp[key] == 0)
        	return -1;
        else{
        	CacheNode * node = find(key);
        	remove(node);
        	insert(node);
        	
        	return mp[key];
        }
    }
    
    CacheNode * find(int key){
    	CacheNode * cur = head->next;
    	while(cur != tail){
    		if(cur->key == key){
    			return cur;
    		}
    		cur = cur->next;
    	}
    }
    
    void pop(){
    	CacheNode * p = tail->prev;
    	CacheNode * pp = p->prev;
		
		pp->next = tail;
		tail->prev = pp;
		
		mp[p->key] = 0;
		
		--size;
		delete p; 
    }
    void remove(CacheNode * node){
		CacheNode * cur_prev = node->prev;
		CacheNode * cur_next = node->next;
		cur_prev->next = cur_next;
		cur_next->prev = cur_prev;
		
		--size;
    }
    
    void insert(CacheNode * node){
    	CacheNode * head_next = head->next;
		head->next = node;
		node->prev = head;
		node->next = head_next;
		head_next->prev = node;
		
		++size;
    }
    
    void set(int key, int value) {
        if(mp[key] == 0){
        	mp[key] = value;
        	if(capacity > 0 && size == capacity){
        		pop();
        	}
        	if(size < capacity){
        		CacheNode * node = new CacheNode(key);
    			insert(node);
        	}
        }else{
        	CacheNode * node = find(key);
        	remove(node);
        	insert(node);
        	mp[key] = value;
        }
    }
    
    void display(){
    	CacheNode * cur = head->next;
    	while(cur != tail){
    		cout<<cur->key<<" ";
    		cur = cur->next;
    	}
    	cout<<endl;
    }
};

int main(){
	LRUCache lru(3);
	
	int key[]={4,3,4,2,3,1,4,2};
	int val[]={1,2,3,4,5,6,7,8};
	
	for(int i=0;i<8;i++){
		lru.set(key[i],val[i]);
		lru.display();
	}
}
