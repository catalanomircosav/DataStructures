#pragma once

#include<Array/Lista.h>
#include<Array/Pila.h>

namespace Array {
	template<typename T>
	class Pila : public Lista<T> {

	public:
		typedef int pos;

		Pila();
		~Pila();

		bool pilaVuota();
		Nodo<T>* leggiPila();

		void popPila();
		void pushPila(T data);

	private:
		Nodo<T>* head;
	};
}

template<typename T>
Array::Pila<T>::Pila() : head(nullptr) {}

template<typename T>
Array::Pila<T>::~Pila() {}

template<typename T>
bool Array::Pila<T>::pilaVuota() { return this->listaVuota(); }

template<typename T>
Array::Nodo<T>* Array::Pila<T>::leggiPila() {
	assert(this->listaVuota() && this->size >= 1, "Pila vuota.");
	
	this->leggiLista(this->primoLista());
}

template<typename T>
void Array::Pila<T>::popPila() {
	assert(this->size >= 1, "Pila vuota.");
	
	this->cancLista(this->primoLista());
}

template<typename T>
void Array::Pila<T>::pushPila(T data) {
	// assert(this->listaVuota() && this->size >= 0, "Pila vuota.");
	this->insLista(data, this->primoLista());
}