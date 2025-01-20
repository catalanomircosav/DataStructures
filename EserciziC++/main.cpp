#include <Array/Pila.h>
#include <Array/Lista.h>

int main(int argc, char** argv) {
	Array::Pila<int>* pila = new Array::Pila<int>();

	std::cout << "Inserisco 3 nodi:\n";
	pila->pushPila(10);
	pila->pushPila(20);
	pila->pushPila(30);
	
	pila->stampaLista();

	std::cout << "Elimino un nodo:\n";
	pila->popPila();
	pila->stampaLista();
	system("pause");
	return 0;
}