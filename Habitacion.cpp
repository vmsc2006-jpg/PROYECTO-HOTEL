#pragma once
#include <iostream>
#include <string>
#include "IOperacionHotel.cpp"
using namespace std;

class Habitacion : public IOperacionHotel {
    protected:
    string codigoHabitacion;
    float precioRenta;
    string estatus; // "Disponible" o "Rentada"

    public:
    Habitacion();
    virtual ~Habitacion() {}

    void setCodigoHabitacion(string);
    string getCodigoHabitacion();

    void setPrecioRenta(float);
    float getPrecioRenta();

    void setEstatus(string);
    string getEstatus();

    // Método virtual puro de polimorfismo
    virtual string getTipoHabitacion() = 0; 

    // Implementación de la Interfaz
    void mostrarDetalles(); 
};

Habitacion::Habitacion() {
    codigoHabitacion = "";
    precioRenta = 0.0;
    estatus = "Disponible"; // Por defecto al crearse
}

void Habitacion::setCodigoHabitacion(string codigoHabitacion) {
    this->codigoHabitacion = codigoHabitacion;
}
string Habitacion::getCodigoHabitacion() {
    return this->codigoHabitacion;
}

void Habitacion::setPrecioRenta(float precioRenta) {
    this->precioRenta = precioRenta;
}
float Habitacion::getPrecioRenta() {
    return this->precioRenta;
}

void Habitacion::setEstatus(string estatus) {
    this->estatus = estatus;
}
string Habitacion::getEstatus() {
    return this->estatus;
}

void Habitacion::mostrarDetalles() {
    cout << "Codigo: " << codigoHabitacion 
         << " | Tipo: " << getTipoHabitacion() 
         << " | Precio: $" << precioRenta 
         << " | Estatus: " << estatus << endl;
}