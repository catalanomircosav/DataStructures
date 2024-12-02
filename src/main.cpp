#include <iostream>
#include <Array/Coda.h>

int main() {
    // Crea una coda di interi
    Coda<int> queue;

    // Crea alcuni nodi
    auto node1 = new Node<int>(1);
    auto node2 = new Node<int>(2);
    auto node3 = new Node<int>(3);

    // Aggiungi nodi alla coda
    queue.push(node1);
    queue.push(node2);
    queue.push(node3);

    // Stampa la coda
    std::cout << "Coda dopo aver aggiunto i nodi: ";
    queue.printArray();
    std::cout << std::endl;

    // Rimuovi il primo nodo
    queue.pop();
    std::cout << "Coda dopo aver rimosso il primo nodo: ";
    queue.printArray();
    std::cout << std::endl;

    return 0;
}
