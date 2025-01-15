#include <Servizio.h>

int main(int argc, char** argv) {

	Lista::Lista<int>* lista = new Lista::Lista<int>();

	lista->insLista(1, 1);
	lista->insLista(2, 2);
	lista->insLista(3, 3);
	lista->insLista(4, 2);
	lista->insLista(5, 1);

	std::cout << "Lista iniziale:\n";
	lista->stampaLista();
	std::cout << "\nLista con un valore sostituito:\n";
	lista->scriviLista(10, 1);
	lista->stampaLista();
	std::cout << "\nLista con un valore cancellato:\n";
	lista->cancLista(1);
	lista->stampaLista();

	system("pause");
	return 0;
}