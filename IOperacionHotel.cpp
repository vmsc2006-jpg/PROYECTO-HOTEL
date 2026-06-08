#pragma once
#include <iostream>
using namespace std;

class IOperacionHotel {
    public:
    // Método virtual puro (hace que esta clase sea una interfaz en C++)
    virtual void mostrarDetalles() = 0; 
    virtual ~IOperacionHotel() {}
};