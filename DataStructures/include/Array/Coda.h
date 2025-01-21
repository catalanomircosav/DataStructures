#pragma once
#include<Array/Nodo.h>

namespace Array {
	template<typename T>
	class Coda {
	public:
		typedef int pos;
		typedef Nodo<T>* val;

		Coda();
		~Coda();

		bool codaVuota() const;

		T leggiCoda();

		void fuoriCoda();
		void inCoda(T);

	private:
		int size;
		Nodo<T>* head, * tail;
	};
}

// ? implementazione
template<typename T>
Array::Coda<T>::Coda() : size(0), head(nullptr), tail(nullptr) {};

template<typename T>
Array::Coda<T>::~Coda() {
	while (!codaVuota())
		fuoriCoda();
}

template<typename T>
bool Array::Coda<T>::codaVuota() const {
	return head == nullptr && size == 0;
}

template<typename T>
typename T Array::Coda<T>::leggiCoda() {
	assert(size >= 1 && !codaVuota(), "Coda vuota.");

	return head->leggiNodo();
}

// inserisco in coda esco dalla testa
template<typename T>
void Array::Coda<T>::fuoriCoda() {
	assert(size >= 1 && !codaVuota(), "Coda vuota.");

	Nodo<T>* nodo = head;

	if (head->leggiNext()) {
		head = head->leggiNext();
		head->scriviPrev(nullptr);
	}
	else {
		head = nullptr;
		tail = nullptr;
	}

	delete nodo;
	size--;
}

template<typename T>
void Array::Coda<T>::inCoda(T data) {

	val nuovo = new Nodo<T>(data);
	if (tail) {
		tail->scriviNext(nuovo);
		nuovo->scriviPrev(tail);
	}
	else {
		head = nuovo;
	}

	tail = nuovo;
	size++;
}
