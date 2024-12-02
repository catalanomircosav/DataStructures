#pragma once
#include "Array.h"

template<class T>
class Coda : public Array<T> {
public:
    void push(typename Array<T>::nodePtr) override;
    void pop() override;      
};

template<class T>
void Coda<T>::push(typename Array<T>::nodePtr node) {
    Array<T>::push(node);  // Inserisci alla fine della lista
}

template<class T>
void Coda<T>::pop() {
    if (!this->isEmpty()) {
        typename Array<T>::nodePtr temp = this->head;
        this->head = this->head->getNext();
        if (this->head != nullptr) {
            this->head->setPrev(nullptr);
        } else {
            this->tail = nullptr;
        }
        delete temp;
    } else {
        throw std::out_of_range("Coda vuota.");
    }
}
