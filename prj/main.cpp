#include <iostream>
using namespace std;
#include <fstream>
#include "ds.cpp"
#include "tree.h"
#include <bitset>
#include <math.h>
void getEncoded(int *numbers, node *elements,node a,int size, int * depth){
	elements[1] = a;
	numbers[1] = 0;
	depth[1] = 0;
	int push = 2;
	for (int i = 1; i < size * 2; ++i){
		if(elements[i].flag == 1){
			node x = *(elements[i].data.pointers.left);
			delete elements[i].data.pointers.left;
			elements[push] = x;
			numbers[push] = numbers[i] * 2;
			depth[push] = depth[i] + 1;
			push++;
			x = *(elements[i].data.pointers.right);
			delete elements[i].data.pointers.right;
			elements[push] = x;
			numbers[push] = numbers[i] * 2 + 1;
			depth[push] = depth[i] + 1;
			push++;
		}
	}
}
void bin(int a, int b){
	char x[sizeof(int) * 8];
	int i = 0;
	x[0] = 0;
	for(; a != 0 ;i++){
		x[i] = a % 2;
		a /= 2;
	}
	if(i == 0)
		i = 1;
	for(int j = b - i; j > 0; j--){
		cout << 0;
	}
	for(i--;i >= 0; i--){
		cout << (int)x[i];
	}
}
int main(){
	/** Open and read file **/
	cout << "please Enter file name::" << endl;
	char address[300];
	cin >> address;
	ifstream myfile;
	myfile.open(address);
	if(myfile.is_open()){
		char c;
		dictTree characterList;
		while(myfile.get(c)){
			/** Get character and save it into a sorted dictionary tree**/
			characterList.push(c);
		}
		//characterList.show();
		/** Create MinHeap **/
		minHeap heapTree(characterList.get_size());
		characterList.ToMinHeap(&heapTree);
		//heapTree.show();
		int numbers[heapTree.get_size() * 2]; //array of characters and their value
		int depth[heapTree.get_size() * 2];
		node elements[heapTree.get_size() * 2];
		int size = heapTree.get_size();
		/** create Tree of character**/
		while(heapTree.get_size() > 1){
			node * a = new node;
			*a = heapTree.remove();
			node *b = new node;
			*b = heapTree.remove();
			node c;
			c.count = a->count + b->count;
			c.flag = 1;
			c.data.pointers.left = a;
			c.data.pointers.right = b;
			heapTree.insert(c);
		}
		//heapTree.show();
		getEncoded(numbers, elements, heapTree.remove(),size,depth);
		for (int i = 1; i < size * 2; ++i){
			if(elements[i].flag == 0){
				cout << elements[i].data.ch << " = ";
				bin(numbers[i],depth[i]);
				cout << endl;
			}
		}
	}else{
		cout << "Can't open file" << endl;
		return 1;
	}
	myfile.close();
	return 0;
}