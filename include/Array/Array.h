#pragma once
#include "Node.h"

/* ======================== DEFINIZIONE ======================== */
template<class T>
class Array {
public:
    using nodePtr = Node<T>*;

    /* ============ Costruttori ============ */
    Array();
    Array(int);
    Array(int, nodePtr, nodePtr);
    
    /* ============ Distruttore ============ */
    virtual ~Array();

    /* ============ Getter e Setter ============ */
    nodePtr getHead() const;
    nodePtr getTail() const;
    nodePtr getNode(int) const;
    
    void setHead(nodePtr);
    void setTail(nodePtr);

    /* ============ Utility ============ */
    void printArray() const;
    bool isEmpty() const;
    bool isFirst(nodePtr node) const;
    bool isLast(nodePtr node) const;

    /* ============ Metodi pubblici ============ */
    virtual void push(nodePtr);
    virtual void push(nodePtr, int);

    virtual void pop();
    virtual void pop(int);

protected:
    /* ============ attributi privati ============ */
    nodePtr head, tail;               // puntatori al primo e ultimo nodo
};

/* ======================== IMPLEMENTAZIONE ======================== */
template<class T>
Array<T>::Array() : head(nullptr), tail(nullptr) { }

template<class T>
Array<T>::Array(int) : head(nullptr), tail(nullptr) { }

template<class T>
Array<T>::Array(int, nodePtr head, nodePtr tail) : head(head), tail(tail) { }

template<class T>
Array<T>::~Array() {
    nodePtr temp;
    while (head != nullptr) {
        temp = head;
        head = head->getNext();

        delete temp;
    }

    head = nullptr;
    tail = nullptr;
}

/* ============ Getter e Setter ============ */
template<class T>
typename Array<T>::nodePtr Array<T>::getHead() const { return head; }

template<class T>
typename Array<T>::nodePtr Array<T>::getTail() const { return tail; }

template<class T>
typename Array<T>::nodePtr Array<T>::getNode(int pos) const {
    nodePtr temp = head;
    for (int i = 0; i < pos && temp != nullptr; ++i) {
        temp = temp->getNext();
    }

    if (!temp) throw std::out_of_range("Posizione non disponibile.");
    else return temp;
}

template<class T>
void Array<T>::setHead(nodePtr node) { head = node; }

template<class T>
void Array<T>::setTail(nodePtr node) { tail = node; }

/* ============ Utility ============ */
template<class T>
void Array<T>::printArray() const {
    nodePtr temp = head;
    while (temp != nullptr) {
        temp->printNode();
        temp = temp->getNext();
    }
}

template<class T>
bool Array<T>::isEmpty() const {
    return head == nullptr;
}

template<class T>
bool Array<T>::isFirst(nodePtr node) const {
    return node == head;
}

template<class T>
bool Array<T>::isLast(nodePtr node) const {
    return node == tail;
}

/* ============ Metodi pubblici ============ */
template<class T>
void Array<T>::push(nodePtr newNode, int pos) {
    if (pos < 0) throw std::out_of_range("Posizione non valida.");

    if (pos == 0) {
        newNode->setNext(head);
        if (head != nullptr)
            head->setPrev(newNode);
        head = newNode;
        if (tail == nullptr)
            tail = newNode;
    } else {
        nodePtr prevNode = getNode(pos - 1);
        nodePtr nextNode = prevNode->getNext();
        newNode->setNext(nextNode);
        newNode->setPrev(prevNode);
        prevNode->setNext(newNode);
        if (nextNode != nullptr)
            nextNode->setPrev(newNode);
        else
            tail = newNode;
    }
}

template<class T>
void Array<T>::push(nodePtr node) {
    if (isEmpty()) {
        head = node;
        tail = node;
    } else {
        node->setPrev(tail);
        tail->setNext(node);
        tail = node;
    }
}

template<class T>
void Array<T>::pop() {
    if (isEmpty()) throw std::out_of_range("Array vuoto.");

    nodePtr temp = tail;
    if (head == tail)
        head = tail = nullptr;
    else {
        tail = tail->getPrev();
        if (tail != nullptr)
            tail->setNext(nullptr);
    }
    delete temp;
}

template<class T>
void Array<T>::pop(int pos) {
    if (pos < 0) throw std::out_of_range("Posizione non valida.");

    if (pos == 0) {
        nodePtr temp = head;
        head = head->getNext();

        if (head != nullptr)
            head->setPrev(nullptr);
        else
            tail = nullptr;
        
        delete temp;

    } else {
        nodePtr prevNode = getNode(pos - 1);
        nodePtr temp = prevNode->getNext();
        prevNode->setNext(temp->getNext());
        
        if (temp->getNext() != nullptr) 
            temp->getNext()->setPrev(prevNode);
        else
            tail = prevNode;
        
        delete temp;
    }
}