#include "lists.hpp"
using std::cout;

int
allocate(int quantity, list& List1, list& List2)
{
	node Node = List1;
	if( getNodeSize(Node) < quantity && nextNode(Node) )
	{
		allocate( quantity, nextNode(Node), List2 );
	}
	else if( getNodeSize(Node) >= quantity )
	{
		insertNode(List2, );
	}
	std::cout << "Bloque de " << quantity << "bytes NO puede er asignado" << std::endl;
	return 1;
}

int
deallocate(int position, list& List1, list& List2)
{
	return 0;
}

int
insertNode(list sourceList, node* Node, int position = 0);

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
