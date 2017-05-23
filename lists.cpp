#include "lists.hpp"
using std::cout;

#include <iostream>
#include <string>

typedef bitset<8> byte;


int
allocate(int quantity, list &List1, list &List2)
{
	nodo Node = List1;
	if( getNodeSize(Node) < quantity && nextNode(Node) )
	{
		allocate( quantity, nextNode(Node), List2 );
	}
	else if( getNodeSize(Node) >= quantity )
	{
		insertNode(List2, quantity );
	}
	std::cout << "Bloque de " << quantity << "bytes NO puede ser asignado" << std::endl;
	return 1;
}

int
deallocate(int position, list &List1, list &List2)
{
	return 0;
}

int
insertNode(list sourceList, node* Node, int position = 0){
	nodo nuevo;
	nuevo=new(struct s_nodo);
	nuevo->siguiente = node;
	node = nuevo; 
	while(nodesta!=NULL){
		node = nodesta->siguiente;
		position++;
	}
}

list
newList();

node*
getNode    (list sourceList, int position);

int
getNodeSize(node sourceNode);

int
deleteNode(list sourceList, int position);

node*
nextNode  (node sourceNode);

int
deleteList(list aList);

int
freeBlocks(list aList);
