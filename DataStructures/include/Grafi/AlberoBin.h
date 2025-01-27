#pragma once
#include <Grafi/Nodo.h>
#include <cassert>

namespace grafi {
	template<typename T>
	class AlberoBinario {
		typedef Nodo<T> pos;

	public:

		AlberoBinario();

		// observer
		bool AlberoVuoto();
		bool DxVuoto(pos*);
		bool SxVuoto(pos*);

		// getters
		pos* Radice();
		pos* Padre(pos*);
		pos* FiglioSx(pos*);
		pos* FiglioDx(pos*);

		// setters
		void SetRadice(pos*);

		// utils
		AlberoBinario CostrAlberoBinario(AlberoBinario*);
		void CancellaSottoAlbero(pos*);

		void StampaInOrder(pos*, int);

	private:
		pos* radice;
	};

	template<typename T>
	AlberoBinario<T>::AlberoBinario() : radice(nullptr) {}

	template<typename T>
	bool AlberoBinario<T>::AlberoVuoto() {
		return (radice == nullptr);
	}

	template<typename T>
	bool AlberoBinario<T>::DxVuoto(pos* u) {
		assert(!AlberoVuoto() && "L'albero e' vuoto.\n");

		return (u->getDx() == nullptr);
	}

	template<typename T>
	bool AlberoBinario<T>::SxVuoto(pos* u) {
		assert(!AlberoVuoto() && "L'albero e' vuoto.\n");

		return (u->getSx() == nullptr);
	}

	template<typename T>
	typename AlberoBinario<T>::pos* AlberoBinario<T>::Radice() {
		assert(!AlberoVuoto() && "L'albero e' vuoto.\n");

		return (radice);
	}

	template<typename T>
	typename AlberoBinario<T>::pos* AlberoBinario<T>::Padre(pos* u) {
		assert(!AlberoVuoto() && "L'albero e' vuoto.\n");

		return (u->getPadre());
	}

	template<typename T>
	typename AlberoBinario<T>::pos* AlberoBinario<T>::FiglioSx(pos* u) {
		assert(!AlberoVuoto() && "L'albero e' vuoto.\n");

		return (u->getSx());
	}

	template<typename T>
	typename AlberoBinario<T>::pos* AlberoBinario<T>::FiglioDx(pos* u) {
		assert(!AlberoVuoto() && "L'albero e' vuoto.\n");

		return (u->getDx());
	}

	template<typename T>
	void AlberoBinario<T>::SetRadice(pos* u) {
		radice = u;
	}

	template<typename T>
	AlberoBinario<T> AlberoBinario<T>::CostrAlberoBinario(AlberoBinario* alb) {
		pos* u = new Nodo<T>();
		u->setPadre(nullptr);

		u->setSx(Radice());
		u->setDx(alb->Radice());

		if (!AlberoVuoto()) Radice()->setPadre(u);
		if (!alb->AlberoVuoto()) alb->Radice()->setPadre(u);

		return (u);
	}

	template<typename T>
	void AlberoBinario<T>::CancellaSottoAlbero(pos* u) {
		// caso base: nodo nullptr, esco dalla ricorsione
		if (u == nullptr) return;

		// caso ricorsivo: se il nodo non è nullptr, richiamo cancellasottoalbero sui figli destro e sinistro
		if (FiglioSx(u)) CancellaSottoAlbero(FiglioSx(u));
		if (FiglioDx(u)) CancellaSottoAlbero(FiglioDx(u));

		// dissociare il nodo dal suo padre
		pos* padre = Padre(u);
		if (padre) {
			if (FiglioSx(padre) == u) {
				padre->getSx()->setPadre(nullptr);
				padre->setSx(nullptr);
			}
			else if (FiglioDx(padre) == u) {
				padre->getDx()->setPadre(nullptr);
				padre->setDx(nullptr);
			}
		}

		// eliminare il nodo
		delete u;
		u = nullptr;
	}


	template<typename T>
	void AlberoBinario<T>::StampaInOrder(pos* u, int livello) {
		// Caso base: se il nodo è nullptr, esco dalla ricorsione
		if (u == nullptr) return;

		// Stampa il figlio destro prima, in modo che il nodo corrente sia stampato sotto
		if (FiglioSx(u)) StampaInOrder(FiglioSx(u), livello + 1);

		// Stampa il nodo corrente
		for (int i = 0; i < livello; i++)
			std::cout << "    ";  // Spazi per l'indentazione in base al livello

		std::cout << u->getData() << "\n";  // Stampa il dato del nodo

		// Stampa il figlio sinistro, sotto il nodo corrente
		if (FiglioDx(u)) StampaInOrder(FiglioDx(u), livello + 1);
	}
}