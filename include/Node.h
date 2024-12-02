#pragma once
#include<iostream>

/* ======================== DEFINIZIONE ======================== */
template<class T>
class Node {
    public:
        /* ============ Costruttori ============ */
        Node();
        Node(const T&);
        Node(const T&, const Node<T>*&, const Node<T>*&);

        /* ============ Distruttore ============ */
        ~Node();

        /* ============ Getter e Setter ============ */
        T getData() const;
        Node<T>* getNext() const;
        Node<T>* getPrev() const;

        void setData(const T&);
        void setNext(Node<T>*);
        void setPrev(Node<T>*);

        /* ============ Utility ============ */
        void printNode() const;

    private:
        /* ============ attributi privati ============ */
        T data;                           // rappresenta il valore del nodo
        Node<T> *next, *prev;             // puntatori al nodo successivo e precedente
};

/* ======================== DEFINIZIONE ======================== */
template<class T>
Node<T>::Node() : data{}, next(nullptr), prev(nullptr) {}

template<class T>
Node<T>::Node(const T& data) : data(data), next(nullptr), prev(nullptr) {}

template<class T>
Node<T>::Node(const T& data, const Node<T>*& next, const Node<T>*& prev) : data(data), next(next), prev(prev) {}

template<class T>
Node<T>::~Node() {}

/* ============ Getter e Setter ============ */
template<class T>
T Node<T>::getData() const { return data; }

template<class T>
Node<T>* Node<T>::getNext() const { return next; }

template<class T>
Node<T>* Node<T>::getPrev() const { return prev; }

template<class T>
void Node<T>::setData(const T& data) { this->data = data; }

template<class T>
void Node<T>::setNext(Node<T>* next) { this->next = next; }

template<class T>
void Node<T>::setPrev(Node<T>* prev) { this->prev = prev; }

/* ============ Utility ============ */
template<class T>
void Node<T>::printNode() const {
    std::cout << "Data: " << data << std::endl;
}