#include <iostream>
#include <string>

#include "lists.hpp"


int
allocate(int quantity, list List1, list List2)
{
	node* Node = List1;
	if( getNodeSize(Node) < quantity && nextNode(Node) )
	{
		allocate( quantity, nextNode(Node), List2 );
	}
	else if( getNodeSize(Node) >= quantity )
	{
		node* newNode;
		insertNode(List2, newNode, quantity );
	}
	std::cout << "Bloque de " << quantity << "bytes NO puede ser asignado" << std::endl;
	return 1;
}

int
deallocate(int position, list List1, list List2)
{
	return 0;
}

int
insertNode(list sourceList, node* Node, int position = 0)
{
	if (position == 0)
	{
		Node->nextNode = sourceList;
		sourceList = Node;
	}
	else
	{
		node* tempNode = sourceList;
		for(int i = 0; i < position;i++)
		{
			if(tempNode->startPoint > position)
			{
				// Se ubica Node como el antecesor de el nodo apuntado
				// por tempNode
				Node->nextNode = tempNode;
				Node->prevNode = tempNode->prevNode;
				
				tempNode->prevNode = Node;
				(Node->prevNode)->nextNode = Node;
			}
			else
			{
				tempNode = tempNode->nextNode;
			}
		}
	}
}

list
newList( int size ){
	node theNode;
	theNode.startPoint = 1;
	theNode.endPoint   = size;
	return 0;
}

node*
getNode    (list sourceList, int position){}

int
getNodeSize(node* sourceNode){}

int
deleteNode(list sourceList, int position){}

node*
nextNode  (node* sourceNode){}

int
deleteList(list aList){}

int
freeBlocks(list aList){}
