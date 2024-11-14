#pragma once

template<class T>
class Nodo {
    public:
        Nodo();
        Nodo(const T&);
        ~Nodo();

        void setData(const T&);
        T getData() const;

        void setNext(const Nodo<T>*&);
        Nodo<T>* getNext() const;
        
        void setPrev(const Nodo<T>*&);
        Nodo<T>* getPrev() const;

    private:
        T data;
        Nodo<T>* next;
        Nodo<T>* prev;
};

template<class T>
Nodo<T>::Nodo() : data(nullptr), next(nullptr), prev(nullptr) {}

template<class T>
Nodo<T>::Nodo(const T& d) : data(d), next(nullptr), prev(nullptr) {}

template<class T>
Nodo<T>::~Nodo() {}

template<class T>
void Nodo<T>::setData(const T& d) {
    data = d;
}

template<class T>
T Nodo<T>::getData() const {
    return data;
}

template<class T>
void Nodo<T>::setNext(const Nodo<T>*& n) {
    next = n;
}

template<class T>
Nodo<T>* Nodo<T>::getNext() const {
    return next;
}

template<class T>
void Nodo<T>::setPrev(const Nodo<T>*& p) {
    prev = p;
}

template<class T>
Nodo<T>* Nodo<T>::getPrev() const {
    return prev;
}