#include <Hash/Dizionario.h>
#include <iostream>
#include <vector>

template<typename T, typename U>
void printDizionario(const Dizionario<T, U>& dict, const std::vector<T>& keys) {
    for (const T& key : keys) {
        std::cout << key << ": " << dict[key] << std::endl;
    }
}

int main() {
    Dizionario<std::string, int> dict;

    dict.insert({ "Uno", 1 });
    dict.insert({ "Due", 2 });
    dict.insert({ "Tre", 3 });

    std::vector<std::string> keys = { "Uno", "Due", "Tre" };
    std::cout << "Contenuto del dizionario:" << std::endl;
    printDizionario(dict, keys);

    dict.remove("Due");

    std::cout << "\nDopo la rimozione di 'Due':" << std::endl;
    keys = { "Uno", "Tre" };
    printDizionario(dict, keys);

    return 0;
}
