#ifndef POINTARRAY_H
#define POINTARRAY_H

#include <iostream>
#include "punto.h"

class PointArray {
    friend std::ostream& operator<<(std::ostream&, const PointArray&);

public:
    PointArray();                                 // constructor por defecto
    PointArray(const Punto arr[], int size);      
    PointArray(const PointArray& other);          
    ~PointArray(); 
    size_t getSize() const;                               

    void push_back(const Punto& p);               
    void insert(const Punto& p, int pos);         
    void remove(int pos);                        


    PointArray& operator=(const PointArray& other);    // operador de asignación
    bool operator==(const PointArray& other) const;    
    bool operator!=(const PointArray& other) const;    
    Punto& operator[](size_t index);                  //escritura modif
    const Punto& operator[](size_t index) const;            //lectura ac sin modif

private:
    size_t size;                                  
    Punto* points;                                
};

#endif
