#ifndef TAREA2_LISTA_HPP
#define TAREA2_LISTA_HPP

struct s_node
{
	int startPoint,endPoint;
	struct s_node* nextNode;
};
typedef struct s_node node;
typedef struct s_node* list;

node*
getNode   (list sourceList, int position);

int
insertNode(list sourceList, node* Node, int position = 0);

int
getNodeSize(node* sourceNode);

list
newList( int size );

int
deleteList(list aList);

int
allocate  (int quantity, list List1, list List2);

int
deallocate(int position, list List1, list List2);

int 
join(node *sourceNode);

int
split(node *sourceNode, int size);
#endif // TAREA2_LISTA_HPP
