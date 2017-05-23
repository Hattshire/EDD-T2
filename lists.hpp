#ifndef TAREA2_LISTA_HPP
#define TAREA2_LISTA_HPP

struct s_node
{
	int startPoint,endPoint;
	byte *data;
	struct s_node* nextNode;
};
typedef struct s_node node;
typedef node* list;

node*
getNode   (list sourceList, int position);

int
insertNode(list sourceList, node* Node, int position = 0);

int
deleteNode(list sourceList, int position);

node*
nextNode  (node sourceNode);

int
getNodeSize(node sourceNode);

list
newList();

int
deleteList(list aList);

int
freeBlocks(list aList);

int
allocate  (int quantity, list& List1, list& List2);

int
deallocate(int position, list& List1, list& List2);

#endif  TAREA2_LISTA_HPP
