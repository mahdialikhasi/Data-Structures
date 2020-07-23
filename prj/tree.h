#ifndef TREE_H
#define TREE_H
class minHeap{
	int capacity;
	node * heap;
	int size;
public:
	minHeap(int capacity);
	~minHeap();	
	void insert(node a);
	void show();
	node remove();
	int get_size();
};
class dictTree{
	dictNode * head;
	int size;
public:
	dictTree();
	~dictTree();
	void push(char c); //push charatcter to dict. if exist :: ++ the count; else : add character to tree
	void show();
	int get_size();
	void ToMinHeap(minHeap * b);
};

#endif 