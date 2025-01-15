#pragma once

#include <Lista.h>

namespace Lista {
	template<typename T>
	void Lista<T>::stampaLista() {
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
}
