#include <iostream>
#include <string>

#include "lists.hpp"


int
allocate(int quantity, list List1, list List2)
{
	node* Node = List1;
	if( getNodeSize(Node->nextNode) < quantity && Node->nextNode->nextNode )
	{
		return allocate( quantity, Node->nextNode, List2 );
	}
	else if( !(getNodeSize(Node->nextNode) < quantity) )
	{
	    split(Node, quantity);
	    
	    node* tmpNode = Node->nextNode;
	    Node->nextNode = tmpNode->nextNode;
	    
		insertNode(List2, tmpNode);
	    std::cout << "Alojados " << quantity << " bytes, ubicados en " << tmpNode->startPoint << "." << std::endl;
	}
	else
	{
	    std::cout << "Bloque de " << quantity << " bytes NO puede ser asignado." << std::endl;
	    return 0;
    }
    return quantity;
}

//
//  Frees the memory block in the position "position"
//
int
deallocate(int position, list List1, list List2)
{	
    // Obtains certain node on certain position on certain list
    node* nodee = getNode(List2,position);
    if(!nodee->nextNode)
    {
        std::cout << "No se ha encontrado el nodo de posicion " << position << std::endl;
        return 1;
    }
    // Unlink the node from List2
    node* tmpNode = nodee->nextNode;
	nodee->nextNode = tmpNode->nextNode;
	
	// Insert the node on List1
	insertNode( List1, tmpNode, position);
	// Join nodee if it has a continuous block on the front
	if (nodee->nextNode->endPoint == nodee->nextNode->nextNode->startPoint - 1)
	{
	    join(nodee->nextNode);
    }
    // Join nodee if it has a continuous block from behind
    else if (nodee->endPoint == nodee->nextNode->startPoint - 1)
    {
        join(nodee);
    }
    std::cout << "Bloque en la posicion " << position << " liberado." << std::endl;
	return 0;
}

int
insertNode(list sourceList, node* Node, int position)
{
	if (position == 0)
	{
		Node->nextNode = sourceList->nextNode;
		sourceList->nextNode = Node;
	}
	else
	{
		node* tempNode = sourceList;
		for(int i = 0; i < position;i++)
		{
			if(tempNode->nextNode->startPoint > position)
			{
				// Se ubica Node como el antecesor de el nodo apuntado
				// por tempNode
				Node->nextNode = tempNode->nextNode;
				tempNode->nextNode = Node;
                i = position;
			}
			else
			{
				tempNode = tempNode->nextNode;
			}
		}

	}
    return 0;
}

list
newList( int size ){
	node* theNode = new node();
	theNode->startPoint = 0;
	theNode->endPoint   = -1;
	if(size > 0)
	{
	    theNode->nextNode = new node();
	    theNode->nextNode->startPoint = 1;
	    theNode->nextNode->endPoint   = size;
	}
	return theNode;
}

node*
getNode    (list sourceList, int position){
	node *nodee = sourceList;
	while ((nodee->nextNode!=NULL) && (nodee->nextNode->startPoint!=position)){
		nodee=nodee->nextNode;
	}
	return nodee;
}



int
deleteList(list aList){
    node* tmpNode = aList->nextNode;
    while(aList)
    {
        delete aList;
        aList = tmpNode;
        tmpNode = aList ? aList->nextNode : NULL;
    }
	return 0;
}

int 
join(node *Node){
	node* oldNode = Node->nextNode;
	Node->endPoint = oldNode->endPoint;
	Node->nextNode = oldNode->nextNode;
	delete oldNode;

	return 0;
}

int split(node* Node, int size)
{
    node* nNode = new node();
    node* cNode = Node->nextNode;
    
    nNode->endPoint = cNode->endPoint;
    
    cNode->endPoint = cNode->startPoint + size - 1;
    nNode->startPoint = cNode->endPoint + 1;
    
    nNode->nextNode = cNode->nextNode;
    cNode->nextNode = nNode;
    return 0;
}

int
getNodeSize(node* sourceNode)
{
    return sourceNode->endPoint - sourceNode->startPoint + 1;
}
