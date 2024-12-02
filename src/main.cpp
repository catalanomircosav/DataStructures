#include "Node.h"

int main() {
    Node<int> nodo1(5);
    Node<int> nodo2(4);
    Node<int> nodo3(3);

    nodo1.setNext(&nodo2);
    nodo2.setNext(&nodo3);
    nodo3.setNext(nullptr);

    nodo3.setPrev(&nodo2);
    nodo2.setPrev(&nodo1);
    nodo1.setPrev(nullptr);

    Node<int>* current = &nodo1;
    
    while(current != nullptr) {
        current->printNode();
        current = current->getNext();
    }

    return 0;
}