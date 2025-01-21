#pragma once
// ? LIBRERIE
#include <iostream>

#define assert(cnd, msg) { \
    if(!cnd) { \
        std::cerr << "Errore: " << msg << std::endl; \
        std::abort(); \
    } \
} \

// ! DEFINIZIONE CLASSE TEMPLATE NODO
namespace Array {
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
}
// ! implementazione

// ? costruttore di default
template<typename T>
Array::Nodo<T>::Nodo() : data{}, next(nullptr), prev(nullptr) {}

template<typename T>
Array::Nodo<T>::Nodo(const T& data) : data(data), next(nullptr), prev(nullptr) {
}

// ? costruttore di copia
template<typename T>
Array::Nodo<T>::Nodo(const Nodo& other)
    : data(other.data), next(nullptr), prev(nullptr) {
    // ? Non copiamo i puntatori `next` e `prev` per evitare
    // ? duplicati indesiderati
}

// ? distruttore
template<typename T>
Array::Nodo<T>::~Nodo() {
    // ? I puntatori `next` e `prev` non vengono eliminati per
    // ? evitare problemi di double deletion
    next = nullptr;
    prev = nullptr;
}

// ? SETTERS
template<typename T>
void Array::Nodo<T>::scriviNodo(const T& data) { this->data = data; }

template<typename T>
void Array::Nodo<T>::scriviNext(Nodo<T>* next) { this->next = next; }

template<typename T>
void Array::Nodo<T>::scriviPrev(Nodo<T>* prev) { this->prev = prev; }

// ? GETTERS
template<typename T>
T Array::Nodo<T>::leggiNodo() const { return data; }

template<typename T>
Array::Nodo<T>* Array::Nodo<T>::leggiNext() const { return next; }

template<typename T>
Array::Nodo<T>* Array::Nodo<T>::leggiPrev() const { return prev; }

// ? sovraccarico di operatori (==)
template<typename T>
bool Array::Nodo<T>::operator==(const Array::Nodo<T>& other) const {
    return this->data == other.data;
}
