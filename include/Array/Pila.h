#pragma once
#include <Array/Array.h>

template<class T>
class Pila : public Array<T> {
    public:
        void push(typename Array<T>::nodePtr) override;
        void pop() override;      
};

template<class T>
void Pila<T>::push(typename Array<T>::nodePtr node) {
    Array<T>::push(node);
}

template<class T>
void Pila<T>::pop() {
    Array<T>::pop();
}