#include <iostream>
#include <Array/Coda.h>

int main() {
    // Creazione della coda di interi
    Array::Coda<int>* coda = new Array::Coda<int>();

    // Aggiunta di elementi alla coda
    coda->inCoda(10);
    coda->inCoda(20);
    coda->inCoda(30);

    std::cout << "Tutta la coda:\n";
    coda->stampaCoda();

    std::cout << "Rimuovo elemento:\n";
    coda->fuoriCoda();
    coda->stampaCoda();

    std::cout << "Inserisco elemento:\n";
    coda->inCoda(40);

    coda->stampaCoda();

    return 0;
}
