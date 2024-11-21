#include "pointarray.h"
#include <iostream>


PointArray::PointArray() : size{0}, points{new Punto[size]} {}


PointArray::PointArray(const Punto arr[], int s) : size{s}, points{new Punto[size]} {
    for (size_t i{0}; i < size; i++) {
        points[i] = arr[i];
    }
}


PointArray::PointArray(const PointArray& other) : size{other.size}, points{new Punto[size]} {
    for (size_t i{0}; i < size; i++) {
        points[i] = other.points[i];
    }
}


PointArray::~PointArray() {
    delete[] points;
}


size_t PointArray::getSize() const {
    return size;
}

// añadir un punto al final del arreglo
void PointArray::push_back(const Punto& p) {
    Punto* tmp = new Punto[size + 1];
    for (size_t i{0}; i < size; i++) {
        tmp[i] = points[i];
    }
    size++;
    delete[] points;
    points = tmp;
    points[size - 1] = p;
}

// insertar un punto en una posición específica
void PointArray::insert(const Punto& p, int pos) {
    if (pos < 0 || pos > size) return;

    Punto* tmp = new Punto[size + 1];
    for (size_t i{0}; i < pos; i++) {
        tmp[i] = points[i];
    }
    tmp[pos] = p;
    for (size_t i{pos}; i < size; i++) {
        tmp[i + 1] = points[i];
    }
    size++;
    delete[] points;
    points = tmp;
}

// eliminar un punto de una posición específica
void PointArray::remove(int pos) {
    if (pos < 0 || pos >= size) return;

    Punto* tmp = new Punto[size - 1];
    for (size_t i{0}; i < size; i++) {
        if (i < pos) {
            tmp[i] = points[i];
        } else if (i > pos) {
            tmp[i - 1] = points[i];
        }
    }
    size--;
    delete[] points;
    points = tmp;
}

// sobrecarga del operador <<
std::ostream& operator<<(std::ostream& output, const PointArray& pa) {
    output << "[ ";
    for (size_t i{0}; i < pa.size; ++i) {
        output << pa.points[i] << " ";
    }
    output << "]";
    return output;
}

PointArray& PointArray::operator=(const PointArray& other) {
    if (this == &other) {
        return *this; // evitar autoasignación
    }
    delete[] points; // liberar memoria existente
    size = other.size;
    points = new Punto[size];
    for (size_t i{0}; i < size; ++i) {
        points[i] = other.points[i];
    }
    return *this;
}


bool PointArray::operator==(const PointArray& other) const {
    if (size != other.size) {
        return false; // los tamaños son diferentes
    }
    for (size_t i{0}; i < size; ++i) {
        if (!(points[i] == other.points[i])) { // usa el operador == de Punto
            return false;
        }
    }
    return true; // todos los puntos son iguales
}

bool PointArray::operator!=(const PointArray& other) const {
    return !(*this == other); // reutiliza el operador ==
}


Punto& PointArray::operator[](size_t index) {
    if (index >= size) {
        throw std::out_of_range("Índice fuera de rango");
    }
    return points[index];
}

const Punto& PointArray::operator[](size_t index) const {
    if (index >= size) {
        throw std::out_of_range("Índice fuera de rango");
    }
    return points[index];
}
