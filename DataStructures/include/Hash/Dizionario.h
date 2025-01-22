#pragma once
#include <Array/Lista.h>
#include <vector>

template<typename T, typename U>
class Dizionario {
public:
	Dizionario();
	~Dizionario();

	bool isEmpty() const;
	bool has(const T&) const;
	
	void insert(std::pair<T, U>);
	void remove(const T&);

	U operator[](const T&) const;

private:
	std::vector<T> keys;
	std::vector<U> values;
};

template<typename T, typename U>
Dizionario<T, U>::Dizionario() : keys{}, values{} {}

template<typename T, typename U>
Dizionario<T, U>::~Dizionario() {
	keys.clear();
	values.clear();
}

template<typename T, typename U>
bool Dizionario<T, U>::isEmpty() const {
	return keys.size() == 0 && values.size() == 0;
}

template<typename T, typename U>
bool Dizionario<T, U>::has(const T& key) const {
	for (T currentKey : keys) {
		if (currentKey == key) {
			return true;
		}
	}
	return false;
}

template<typename T, typename U>
void Dizionario<T, U>::insert(std::pair<T, U> entry) {
	keys.push_back(entry.first);
	values.push_back(entry.second);

}

template<typename T, typename U>
void Dizionario<T, U>::remove(const T& key) {
	assert(!isEmpty(), "Dizionario vuoto.");
	unsigned int pos = 0;

	for (T currentKey : keys) {
		if (currentKey == key) {
			keys.erase(keys.begin() + pos);
			values.erase(values.begin() + pos);
			return;
		}
		pos++;
	}
}

template<typename T, typename U>
U Dizionario<T, U>::operator[](const T& key) const {
	assert(!isEmpty(), "Dizionario vuoto.");

	unsigned int pos = std::find(keys.begin(), keys.end(), key) - keys.begin();

	return values[pos];
}