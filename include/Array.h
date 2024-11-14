#pragma once
#include<Nodo.h>

template<class T>
class Array {
    public:
        // iterator
        typedef Nodo<T>* iterator;

        // constructors and destructors
        Array();
        virtual ~Array();

        // push and pop operations        
        virtual void push(const T& value) = 0;
        virtual void pop(const T& value) = 0;
        virtual void pop(int pos) = 0;
        virtual void pop(iterator it) = 0;

        // utils
        void print() const;
        void print(int pos) const;
        void print(iterator it) const;

        bool isEmpty() const;
        bool isFirst(iterator it) const;
        bool isLast(iterator it) const;

        // operators overloading
        bool operator==(const Array<T>& other) const;

        // algorithms
        int search(const T& value) const;
        void order() const;        

    private:
        iterator _head;
        iterator _tail;
};

template<class T>
Array<T>::Array() : _head(nullptr), _tail(nullptr) {}

template<class T>
Array<T>::~Array() {}

template<class T>
void Array<T>::print() const {
    iterator it = _head;
    while (it!= nullptr) {
        std::cout << it->getData() << " ";
        it = it->getNext();
    }
    std::cout << std::endl;
}

template<class T>
void Array<T>::print(int pos) const {
    iterator it = _head;

    if(pos < 0) throw std::out_of_range("Invalid position");
    
    for(int i = 0; i < pos && it != nullptr; i++) it = it->getNext();
    if(!it) throw std::out_of_range("Invalid position");

    std::cout << it->getData() << std::endl;
}

template<class T>
void Array<T>::print(iterator it) const {
    std::cout << it->getData() << std::endl;
}

template<class T>
bool Array<T>::isEmpty() const { return _head == nullptr; }
template<class T>
bool Array<T>::isFirst(iterator it) const { return it == _head; }

template<class T>
bool Array<T>::isLast(iterator it) const { return it == _tail; }

// operators overloading
// ! todo: remake this!
template<class T>
bool Array<T>::operator==(const Array<T>& other) const {
    return (this == other);
}
