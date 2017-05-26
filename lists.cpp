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
        return tmpNode->startPoint;
	}
	else
	{
	    return 0;
    }
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
        return 1;
    }
    // Unlink the node from List2
    node* tmpNode = nodee->nextNode;
	nodee->nextNode = tmpNode->nextNode;
	
	// Insert the node on List1
	insertNode( List1, tmpNode, position);
	return getNodeSize(tmpNode);
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

	            // Join nodee if it has a continuous block on the front
	            if (Node->endPoint == Node->nextNode->startPoint - 1)
	            {
	                join(Node);
                }
                // Join nodee if it has a continuous block from behind
                if (tempNode->endPoint == Node->startPoint - 1)
                {
                    join(tempNode);
                }
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
    node* tmpNode;
    while(aList)
    {
        tmpNode = aList->nextNode;
        delete aList;
        aList = tmpNode;
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
    if(getNodeSize(Node) == size)
        return size;
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
