/**Proyecto: Restaurant
 * Nombre: Shaula Suhail Paz Garay
 * Metricula: A01712013
 * Fecha: 18 de septiembre de 2024
 */

#ifndef SORTS_H
#define SORTS_H

#include <vector>

template <class T>
class Sorts {
private:
	void swap(std::vector<T>&, int, int);
public:
	std::vector<T> bubbleSort(const std::vector<T>&);
};

template <class T>
void Sorts<T>::swap(std::vector<T> &v, int i, int j) {
	T aux = v[i];
	v[i] = v[j];
	v[j] = aux;
}

template <class T>
std::vector<T> Sorts<T>::bubbleSort(const std::vector<T> &source) {
	std::vector<T> v;
    v = source;

	for (int i = v.size() - 1; i > 0; i--)
		for (int j = 0; j < i; j++)
			if (v[j] > v[j + 1])
				swap(v, j, j + 1);
	return v;
}

#endif