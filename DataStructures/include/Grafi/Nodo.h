#pragma once
#include<iostream>

namespace grafi {
	template<typename T>
	class Nodo {
	public:
		typedef Nodo<T> pos;

		// costruttori
		Nodo();
		Nodo(T);
		~Nodo() = default;

		// getters
		pos* getPadre() const;
		pos* getDx() const;
		pos* getSx() const;
		T getData() const;
		int getProfondità() const;

		// setters
		void setPadre(pos*);
		void setDx(pos*);
		void setSx(pos*);
		void setData(T);
		void setProfondità(int);
		// utils
		void stampaNodo();

		// overload di operatori
		pos& operator=(const pos&);

		bool operator==(const pos&);
		bool operator!=(const pos&);

		int profondità;

	private:
		pos *padre;		// puntatore al nodo padre
		
		pos *sx;		// puntatori ai nodi figli
		pos *dx;


		T data;			// valore del nodo corrente
	};

	/* =====================================
	============== COSTRUTTORI =============
	===================================== */

	template<typename T>
	Nodo<T>::Nodo() : padre(nullptr), dx(nullptr), sx(nullptr), data{}, profondità(-1) {}

	template<typename T>
	Nodo<T>::Nodo(T data) : padre(nullptr), dx(nullptr), sx(nullptr), data(data) {}

	/* =====================================
	================ GETTERS ===============
	===================================== */

	template<typename T>
	typename Nodo<T>::pos* Nodo<T>::getPadre() const { return padre; }

	template<typename T>
	typename Nodo<T>::pos* Nodo<T>::getDx() const { return dx; }

	template<typename T>
	typename Nodo<T>::pos* Nodo<T>::getSx() const { return sx; }

	template<typename T>
	T Nodo<T>::getData() const { return data; }

	template<typename T>
	int Nodo<T>::getProfondità() const { return profondità; }

	/* =====================================
	================ SETTERS ===============
	===================================== */

	template<typename T>
	void Nodo<T>::setPadre(pos* padre) { this->padre = padre; }

	template<typename T>
	void Nodo<T>::setDx(pos* dx) { this->dx = dx; }

	template<typename T>
	void Nodo<T>::setSx(pos* sx) { this->sx = sx; }

	template<typename T>
	void Nodo<T>::setData(T data) { this->data = data; }

	template<typename T>
	void Nodo<T>::setProfondità(int profondità) { this->profondità = profondità; }

	/* =====================================
	=============== OPERATORI ==============
	===================================== */

	template<typename T>
	typename Nodo<T>::pos& Nodo<T>::operator=(const pos& other) {
		if (this != &other) {
			this->setPadre(other.getPadre());
			this->setDx(other.getDx());
			this->setSx(other.getSx());
			this->setData(other.getData());
		}

		return *this;
	}

	template<typename T>
	bool Nodo<T>::operator==(const pos& other) {
		return this->getData() == other.getData();
	}

	template<typename T>
	bool Nodo<T>::operator!=(const pos& other) {
		return this->getData() != other.getData();
	}

	/* =====================================
	================= UTILS ================
	===================================== */

	template<typename T>
	void Nodo<T>::stampaNodo() {
		std::cout << this->getData();
	}
}