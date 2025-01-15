#pragma once

// ? LIBRERIE
#include <iostream>

// ! DEFINIZIONE CLASSE TEMPLATE NODO
template<typename T>
class Nodo {
public:
    // ! costruttori
    Nodo();
    Nodo(const T& data); // ? costruttore con parametro
    Nodo(const Nodo& other); // ? costruttore di copia

    ~Nodo();

    // ? SETTERS
    void scriviNodo(const T& data);
    void scriviNext(Nodo<T>* next);
    void scriviPrev(Nodo<T>* prev);

    // ? GETTERS
    T leggiNodo() const;
    Nodo<T>* leggiNext() const;
    Nodo<T>* leggiPrev() const;

    // ? sovraccarico di operatore ==
    bool operator==(const Nodo& other) const;

private:
    T data;

    // ? nodi precedente e successivo
    Nodo<T>* next;
    Nodo<T>* prev;
};

// ! implementazione

// ? costruttore di default
template<typename T>
Nodo<T>::Nodo() : data{}, next(nullptr), prev(nullptr) {}

template<typename T>
Nodo<T>::Nodo(const T& data) : data(data), next(nullptr), prev(nullptr) {
}

// ? costruttore di copia
template<typename T>
Nodo<T>::Nodo(const Nodo& other)
    : data(other.data), next(nullptr), prev(nullptr) {
    // ? Non copiamo i puntatori `next` e `prev` per evitare
    // ? duplicati indesiderati
}

// ? distruttore
template<typename T>
Nodo<T>::~Nodo() {
    // ? I puntatori `next` e `prev` non vengono eliminati per
    // ? evitare problemi di double deletion
    next = nullptr;
    prev = nullptr;
}

// ? SETTERS
template<typename T>
void Nodo<T>::scriviNodo(const T& data) { this->data = data; }

template<typename T>
void Nodo<T>::scriviNext(Nodo<T>* next) { this->next = next; }

template<typename T>
void Nodo<T>::scriviPrev(Nodo<T>* prev) { this->prev = prev; }

// ? GETTERS
template<typename T>
T Nodo<T>::leggiNodo() const { return data; }

template<typename T>
Nodo<T>* Nodo<T>::leggiNext() const { return next; }

template<typename T>
Nodo<T>* Nodo<T>::leggiPrev() const { return prev; }

// ? sovraccarico di operatori (==)
template<typename T>
bool Nodo<T>::operator==(const Nodo& other) const {
    return this->data == other.data;
}
