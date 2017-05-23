#ifndef TAREA2_LISTA_HPP
#define TAREA2_LISTA_HPP

struct s_node
{
	int startPoint,endPoint;
	struct s_node* nextNode;
	struct s_node* prevNode;
};
typedef struct s_node node;
typedef struct s_node* list;

node*
getNode   (list sourceList, int position);

int
insertNode(list sourceList, node* Node, int position);

int
deleteNode(list sourceList, int position);

node*
nextNode  (node* sourceNode);

int
getNodeSize(node* sourceNode);

list
newList( int size );

int
deleteList(list aList);

int
freeBlocks(list aList);

int
allocate  (int quantity, list List1, list List2);

int
deallocate(int position, list List1, list List2);

#endif // TAREA2_LISTA_HPP
