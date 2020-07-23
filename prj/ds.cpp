#ifndef DS_H
#define DS_H

typedef struct dictNode{
	char data;
	int count;
	dictNode * right;
	dictNode * left;
} dictNode;

typedef struct node{
	int count;
	int flag; //0 for leaf and 1 for node
	union{
		char ch;
		struct{
			node * right;
			node * left;
		} pointers;
	} data;
} node;
#endif 
