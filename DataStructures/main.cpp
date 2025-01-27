#include <Grafi/AlberoBin.h>
using namespace grafi;

int main(int argc, char** argv) {
    // Creazione di un albero binario
    AlberoBinario<int> albero;

    // Test per verificare se l'albero è vuoto
    std::cout << "L'albero e' vuoto? " << (albero.AlberoVuoto() ? "Si" : "No") << std::endl;

    // Creazione di un nodo e test di inserimento
    Nodo<int>* nodoPadre = new Nodo<int>();
    Nodo<int>* nodoSinistro = new Nodo<int>();
    Nodo<int>* nodoDestro = new Nodo<int>();
    Nodo<int>* nodoSinistro2 = new Nodo<int>(40);
    Nodo<int>* nodoSinistroDestro = new Nodo<int>(50);

    nodoDestro->setData(10);
    nodoSinistro->setData(20);
    nodoPadre->setData(30);

    nodoSinistro->setSx(nodoSinistro2);
    nodoSinistro->setDx(nodoSinistroDestro);
    
    nodoSinistro2->setPadre(nodoSinistro);
    nodoSinistroDestro->setPadre(nodoSinistro);


    nodoPadre->setSx(nodoSinistro);
    nodoSinistro->setPadre(nodoPadre);
    nodoPadre->setDx(nodoDestro);
    nodoDestro->setPadre(nodoPadre);

    albero.SetRadice(nodoPadre); // Impostazione del padre a nullptr

    std::cout << "Radice del nodo padre: " << nodoPadre->getData() << std::endl;
    std::cout << "Nodo sinistro: " << nodoPadre->getSx()->getData() << std::endl;
    std::cout << "Nodo destro: " << nodoPadre->getDx()->getData() << std::endl;

    albero.StampaInOrder(nodoPadre, 0);
    
    // Test della cancellazione di un sottoalbero
    std::cout << "Cancellazione sotto albero sinistro..." << std::endl;
    albero.CancellaSottoAlbero(nodoSinistro);

    // Verifica che l'albero sia vuoto dopo la cancellazione
    std::cout << "L'albero e' vuoto dopo la cancellazione? " << (albero.AlberoVuoto() ? "Si" : "No") << std::endl;
    albero.StampaInOrder(nodoPadre, 0);


    return 0;
}