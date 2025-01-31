#pragma once

#include <Array/Nodo.h>

namespace Array {
	template<typename T>
	class Lista {

	public:
		typedef int pos;

		Lista();
		~Lista();

		// ? osservatori
		bool listaVuota() const;
		bool fineLista(pos) const;

		// ? GETTERS
		T leggiLista(pos);

		// ? altri metodi
		pos primoLista() const { return 1; }
		pos succLista(pos) const;
		pos precLista(pos) const;

		void scriviLista(T, pos);
		void insLista(T, pos);
		void cancLista(pos);
		void stampaLista();

		pos RicercaLista(T);
		void OrdinaLista();
		
		// ? GETTER
		Nodo<T>* getHead() const { return head; }
		// ? attributi pubblici
		pos corrente;
		
	protected:
		int size;

	private:
		Nodo<T>* head, * tail;
	};
}

// ? implementazione

template<typename T>
Array::Lista<T>::Lista() : head(nullptr), tail(nullptr), size(0), corrente(0) {}

template<typename T>
Array::Lista<T>::~Lista() {

	delete head; head = nullptr;
	delete tail; tail = nullptr;
}

template<typename T>
bool Array::Lista<T>::listaVuota() const {
	if (size > 0) return false;

	return true;
}

template<typename T>
bool Array::Lista<T>::fineLista(pos p) const {
	assert(((1 <= p) && (p <= size + 1)), "Posizione non valida.");

	return p == size + 1;
}

template<typename T>
T Array::Lista<T>::leggiLista(pos p) {
	assert(((1 <= p) && (p <= size)), "Posizione non valida.");

	Nodo<T>* tmp = head;

	corrente = this->primoLista();
	while (corrente < p) {
		corrente = this->succLista(corrente);
		tmp = tmp->leggiNext();
		std::cout << tmp->leggiNodo() << "\n";
	}

	return tmp->leggiNodo();
}


template<typename T>
typename Array::Lista<T>::pos Array::Lista<T>::succLista(pos p) const {
	assert(((1 <= p) && (p <= size)), "Posizione non valida.");

	return p + 1;
}

template<typename T>
typename Array::Lista<T>::pos Array::Lista<T>::precLista(pos p) const {
	assert(((2 <= p) && (p <= size)), "Posizione non valida.");

	return p - 1;
}

template<typename T>
void Array::Lista<T>::scriviLista(T data, pos p) {
	assert(((1 <= p) && (p <= size)), "Posizione non valida.");

	Nodo<T>* tmp = head;
	corrente = this->primoLista();
	while (corrente < p - 1 && tmp->leggiNext() != nullptr) {
		tmp = tmp->leggiNext();
		corrente = this->succLista(corrente);
	}

	tmp->scriviNodo(data);
}


template<typename T>
void Array::Lista<T>::insLista(T data, pos p) {
	assert(((1 <= p) && (p <= size + 1)), "Posizione non valida.");

	Nodo<T>* nuovo = new Nodo<T>(data);

	if (p == 1) {
		if (listaVuota()) {
			// inserimento in prima posizione se la lista � vuota
			head = nuovo;
			tail = nuovo;
		}
		else {
			nuovo->scriviNext(head);
			head->scriviPrev(nuovo);
			head = nuovo;
		}
	}
	else if (p == size + 1) {
		// inserimento alla fine della coda (quando sono gi� presenti dei nodi all'interno della lista)
		nuovo->scriviPrev(tail);
		if (tail) tail->scriviNext(nuovo);
		tail = nuovo;
	}
	else {
		// inserimento in mezzo alla lista
		Nodo<T>* tmp = head;
		corrente = this->primoLista();

		while (corrente < p - 1) {
			corrente = this->succLista(corrente);
			tmp = tmp->leggiNext();
		}

		nuovo->scriviNext(tmp->leggiNext());
		nuovo->scriviPrev(tmp);
		tmp->leggiNext()->scriviPrev(nuovo);
		tmp->scriviNext(nuovo);
	}

	size++;
}

template<typename T>
void Array::Lista<T>::cancLista(pos p) {
	assert(((1 <= p) && (p <= size)), "Posizione non valida.");
	assert(!listaVuota(), "Lista vuota.");

	Nodo<T>* tmp = head;
	corrente = this->primoLista();

	while (corrente < p) {
		tmp = tmp->leggiNext();
		corrente = this->succLista(corrente);
	}

	if (tmp->leggiPrev() != nullptr) {
		tmp->leggiPrev()->scriviNext(tmp->leggiNext());
	}
	else {
		head = tmp->leggiNext();
	}

	if (tmp->leggiNext() != nullptr) {
		tmp->leggiNext()->scriviPrev(tmp->leggiPrev());
	}
	else {
		tail = tmp->leggiPrev();
	}

	delete tmp;
	size--;
}

template<typename T>
void Array::Lista<T>::OrdinaLista() {
	assert(!listaVuota(), "Lista vuota.");

	bool scambiato;
	do {
		scambiato = false;
		Nodo<T>* tmp = head;

		// Itera sui nodi della lista per confrontare e scambiare valori
		while (tmp->leggiNext() != nullptr) {
			if (tmp->leggiNodo() > tmp->leggiNext()->leggiNodo()) {
				// Scambia i valori tra tmp e il nodo successivo
				T tempValue = tmp->leggiNodo();
				tmp->scriviNodo(tmp->leggiNext()->leggiNodo());
				tmp->leggiNext()->scriviNodo(tempValue);
				scambiato = true;
			}
			tmp = tmp->leggiNext(); // Vai al prossimo nodo
		}
	} while (scambiato); // Continua finch� ci sono stati scambi
}


template<typename T>
typename Array::Lista<T>::pos Array::Lista<T>::RicercaLista(T data) {
	assert(!listaVuota(), "Lista vuota.");
	// Ordina la lista
	this->OrdinaLista();

	// Posizione iniziale
	corrente = this->primoLista();

	Nodo<T>* tmp = head;

	// Itera sulla lista per cercare il dato
	while (corrente <= size && tmp != nullptr) {
		if (tmp->leggiNodo() == data) {
			return corrente; // Restituisci la posizione
		}

		corrente = this->succLista(corrente);
		tmp = tmp->leggiNext();
	}

	// Se il dato non � trovato, restituisci -1
	return -1;
}

template<typename T>
void Array::Lista<T>::stampaLista() {
	// assert(size >= 1, "Lista vuota.");

	corrente = this->primoLista();
	Nodo<T>* tmp = head;

	// Itera finch� tmp non � nullptr
	while (corrente <= size) {
		std::cout << "[ " << tmp->leggiNodo() << " ]" << " -> ";
		// Passa al nodo successivo
		tmp = tmp->leggiNext();
		corrente = this->succLista(corrente);
	}

	std::cout << "[ nullptr ] \n";
}