#include <iostream>
using namespace std;
#include "ds.cpp"
#include "tree.h"
dictTree::dictTree(){
	head = new dictNode;
	head->data = -1;
	head->count = 0;
	head->left = NULL;
	head->right = NULL;
	size = 1;
}
dictTree::~dictTree(){
	dictNode **list = new dictNode *[size];
	list[0] = head;
	int put = 1;
	for (int i = 0; i < size; ++i){
		if(list[i]->left != NULL){
			list[put] = list[i]->left;
			put++;
		}
		if(list[i]->right != NULL){
			list[put] = list[i]->right;
			put++;
		}
	}
	for (int i = size - 1; i >= 0; --i){
		delete list[i];
	}
	delete[] list;
}
void dictTree::push(char ch){
	dictNode *ptr = head;
	dictNode *ptr_parent = head;
	while(ptr != NULL){
		if(ptr->data == ch){
			ptr->count ++;
			break;
		}else{
			ptr_parent = ptr;
			if(ptr->data > ch){
				ptr = ptr->left;
			}else if(ptr->data < ch){
				ptr = ptr->right;
			}
		}
	}
	if(ptr == NULL){
		dictNode * data = new dictNode;
		data->data = ch;
		data->count = 1;
		data->left = NULL;
		data->right = NULL;
		if(ptr_parent->data > ch){
			ptr_parent->left = data;
		}else if(ptr_parent->data < ch){
			ptr_parent->right = data;
		}
		size++;
	}
}
void dictTree::show(){
	dictNode **list = new dictNode *[size];
	list[0] = head;
	int put = 1;
	for (int i = 0; i < size; ++i){
		if(list[i]->left != NULL){
			list[put] = list[i]->left;
			put++;
		}
		if(list[i]->right != NULL){
			list[put] = list[i]->right;
			put++;
		}
	}
	for (int i = 1; i < size; ++i){
		cout << list[i]->data << "::" << list[i]->count << endl;
	}
	delete[] list;
}
int dictTree::get_size(){
	return this->size;
}
void dictTree::ToMinHeap(minHeap * b){
	dictNode **list = new dictNode *[size];
	list[0] = head;
	int put = 1;
	for (int i = 0; i < size; ++i){
		if(list[i]->left != NULL){
			list[put] = list[i]->left;
			put++;
		}
		if(list[i]->right != NULL){
			list[put] = list[i]->right;
			put++;
		}
	}
	for (int i = 1; i < size; ++i){
		node a;
		a.count = list[i]->count;
		a.flag = 0;
		a.data.ch = list[i]->data;
		b->insert(a);
	}
	delete[] list;
}
minHeap::minHeap(int capacity){
	this->capacity = capacity;
	heap = new node[capacity + 1];
	size = 0;
}
void minHeap::insert(node a){
	int i;
	size++;
	i = size;
	while((i != 1) && (a.count <= heap[i/2].count)){
		heap[i] = heap[i/2];
		i /= 2;
	}
	heap[i] = a;
}
node minHeap::remove(){
	int parent,child;
	node item, temp;
	item = heap[1];
	temp = heap[size];
	size--;
	parent = 1;
	child = 2;
	while(child <= size){
		if((child < size) && (heap[child].count > heap[child+1].count))
			child++;
		if(temp.count <= heap[child].count)
			break;
		heap[parent] = heap[child];
		parent = child;
		child *= 2;
	}
	heap[parent] = temp;
	return item;
}
void minHeap::show(){
	for (int i = 1; i <= size; ++i){
		cout << heap[i].count << endl;
	}
}
minHeap::~minHeap(){
	//cout << "deleted";
}
int minHeap::get_size(){
	return size;
}