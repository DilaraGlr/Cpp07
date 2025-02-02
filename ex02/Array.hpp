#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>

template <typename T>
class Array
{
    private:
        T *_array;
        unsigned int _size;
    
    public:
        // Constructeur par défaut (tableau vide)
        Array() : _array(NULL), _size(0) {}

        // Constructeur avec taille donnée
        Array(unsigned int n) : _array(new T[n]()), _size(n) {}

        // Constructeur de copie
        Array(Array const &src) : _array(NULL), _size(src._size)
        {
            if (_size > 0)
            {
                _array = new T[_size];
                for (unsigned int i = 0; i < _size; i++)
                    _array[i] = src._array[i];
            }
        }

        // Destructeur
        ~Array() { delete[] _array; }

        // Opérateur d'affectation
        Array &operator=(Array const &rhs)
        {
            if (this != &rhs)
            {
                delete[] _array;
                _size = rhs._size;
                _array = new T[_size];
                for (unsigned int i = 0; i < _size; i++)
                    _array[i] = rhs._array[i];
            }
            return *this;
        }

        // Accès aux éléments avec vérification des limites
        T &operator[](unsigned int i)
        {
            if (i >= _size)
                throw std::out_of_range("Index out of range");
            return _array[i];
        }

        // Surcharge pour les objets `const`
        T const &operator[](unsigned int i) const
        {
            if (i >= _size)
                throw std::out_of_range("Index out of range");
            return _array[i];
        }

        // Retourne la taille du tableau
        unsigned int size() const { return _size; }
};

#endif
