#include <iostream>
#include <Array/Coda.h>

int main() {
    // Creazione della coda di interi
    Array::Coda<int>* coda = new Array::Coda<int>();

    // Aggiunta di elementi alla coda
    coda->inCoda(10);
    coda->inCoda(20);
    coda->inCoda(30);

    return 0;
}
