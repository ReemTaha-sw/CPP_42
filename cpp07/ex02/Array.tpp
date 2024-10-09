#include "Array.hpp"

template <typename T>
Array<T>::Array() : _array(NULL), _size(0)
{
	// std::cout << "Array constructor called!\n";
}

template <typename T>
Array<T>::Array(const unsigned int n) : _array(new T[n]()), _size(n)
{
	// std::cout << "Array constructor called!\n";
}

template <typename T>
Array<T>::Array(const Array &obj) : _array(NULL), _size(0)
{
	*this = obj;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &obj)
{
	if (this != &obj) {
        delete[] _array;
        _size = obj._size;
        _array = new T[_size];
        for (unsigned int i = 0; i < _size; i++) {
            _array[i] = obj._array[i];
        }
    }
    return *this;
}

template <typename T>
Array<T>::~Array()
{
	// std::cout << "Array destructor called!\n";
	delete[] _array;
}

template <typename T>
T& Array<T>::operator[](unsigned int index) {
    if (index >= _size) {
        throw std::out_of_range("Index out of bounds");
    }
    return _array[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const {
    if (index >= _size) {
        throw std::out_of_range("Index out of bounds");
    }
    return _array[index];
}

template <typename T>
unsigned int Array<T>::size() const {
    return _size;
}

