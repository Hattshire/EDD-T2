#include <iostream>
#include <string>
using namespace std;

typedef bitset<8> byte;

struct s_nodo
{ 	byte* valor;
	struct nodo* siguiente;
	int inicio, final;
};

typedef struct s_nodo *nodo;

