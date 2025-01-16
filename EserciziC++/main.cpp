#include <Lista.h>

int main(int argc, char** argv) {
	Lista::Lista<int>* lista = new Lista::Lista<int>();

	lista->insLista(1, 1);
	lista->insLista(2, 2);
	lista->insLista(-1, 3);

	std::cout << "Lista Iniziale: \n";
	lista->stampaLista();

	std::cout << "Lista Ordinata: \n";
	lista->OrdinaLista();
	lista->stampaLista();

	std::cout << "Posizione dell'elemento cercato (ordinato): " << lista->RicercaLista(2) << std::endl;

	system("pause");
	return 0;
}