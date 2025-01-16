#pragma once

#include <Nodo.h>

#define assert(cnd, msg) { \
    if(!cnd) { \
        std::cerr << "Errore: " << msg << std::endl; \
        std::abort(); \
    } \
} \

namespace Lista {
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
		pos RicercaLista(T data);
		// ? attributi pubblici
		pos corrente;

		void scriviLista(T, pos);
		void insLista(T, pos);
		void cancLista(pos);

		void stampaLista();
		void OrdinaLista();

	private:
		int size;
		Nodo<T>* head, * tail;
	};
}

// ? implementazione
template<typename T>
Lista::Lista<T>::Lista() : head(nullptr), tail(nullptr), size(0), corrente(0) {}

template<typename T>
Lista::Lista<T>::~Lista() {

	delete head; head = nullptr;
	delete tail; tail = nullptr;
}

template<typename T>
bool Lista::Lista<T>::listaVuota() const {
	if (size > 0 && head->leggiNext() != nullptr) {
		return false;
	}

	return true;
}

template<typename T>
bool Lista::Lista<T>::fineLista(pos p) const {
	assert(((1 <= p) && (p <= size + 1)), "Posizione non valida.");

	return p == size + 1;
}

template<typename T>
T Lista::Lista<T>::leggiLista(pos p) {
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
typename Lista::Lista<T>::pos Lista::Lista<T>::succLista(pos p) const {
	assert(((1 <= p) && (p <= size)), "Posizione non valida.");

	return p + 1;
}

template<typename T>
typename Lista::Lista<T>::pos Lista::Lista<T>::precLista(pos p) const {
	assert(((2 <= p) && (p <= size)), "Posizione non valida.");

	return p - 1;
}

template<typename T>
void Lista::Lista<T>::scriviLista(T data, pos p) {
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
void Lista::Lista<T>::insLista(T data, pos p) {
	assert(((1 <= p) && (p <= size + 1)), "Posizione non valida.");

	Nodo<T>* nuovo = new Nodo<T>(data);

	if (p == 1) {
		if (this->listaVuota()) {
			// inserimento in prima posizione se la lista è vuota
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
		// inserimento alla fine della coda (quando sono già presenti dei nodi all'interno della lista)
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
void Lista::Lista<T>::cancLista(pos p) {
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


// ! ESERCIZI
template<typename T>
typename Lista::Lista<T>::pos Lista::Lista<T>::RicercaLista(T data) {
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

	// Se il dato non è trovato, restituisci -1
	return -1;
}


template<typename T>
void Lista::Lista<T>::OrdinaLista() {
	assert(!listaVuota(), "Lista vuota.");
	assert(size == 1, "Lista contiene un solo elemento.");
	
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
	} while (scambiato); // Continua finché ci sono stati scambi
}

template<typename T>
void Lista::Lista<T>::stampaLista() {
	assert((!listaVuota()), "Lista vuota.");

	corrente = this->primoLista();
	Nodo<T>* tmp = head;

	// Itera finché tmp non è nullptr
	while (corrente <= size && tmp != nullptr) {
		std::cout << "[ " << tmp->leggiNodo() << " ]" << " -> ";
		// Passa al nodo successivo
		tmp = tmp->leggiNext();
		corrente = this->succLista(corrente);
	}

	std::cout << "[ nullptr ] \n";
}