#include <Lista.h>

int main(int argc, char** argv) {
    Lista::Lista<int>* lista = new Lista::Lista<int>();

    lista->insLista(7, 1);
    lista->insLista(3, 2);
    lista->insLista(10, 3);
    lista->insLista(1, 4);

    std::cout << "Lista prima della ricerca:\n";
    lista->stampaLista();

    // Ricerca di un elemento
    int valore = 10;
    auto posizione = lista->RicercaLista(valore);
    std::cout << "Lista Ordinata:\n";
    lista->stampaLista();

    if (posizione != -1) {
        std::cout << "Valore " << valore << " trovato in posizione: " << posizione << "\n";
    }
    else {
        std::cout << "Valore " << valore << " non trovato nella lista.\n";
    }

    system("pause");
    return 0;
}