#pragma once
#include <iostream>
#include <string>
#include "IOperacionHotel.cpp"
using namespace std;

class Renta : public IOperacionHotel {
    private:
    string codigoHabitacion;
    string codigoCliente;
    int dias;
    float costoTotal;
    string codigoEmpleado;
    float cargosRoomService;

    public:
    // Constructor con parámetros
    Renta(string, string, int, float, string);
    
    // Solo Getters
    string getCodigoHabitacion();
    string getCodigoCliente();
    int getDias();
    float getCostoTotal();
    string getCodigoEmpleado();

    //Implementcacion del room service
    void agregarCargosRoomService(float costoAdicional);

    // Implementación de la Interfaz
    void mostrarDetalles();
};

Renta::Renta(string codHab, string codCli, int d, float precioDia, string codEmp) {
    this->codigoHabitacion = codHab;
    this->codigoCliente = codCli;
    this->dias = d;
    this->costoTotal = d * precioDia;
    this->codigoEmpleado = codEmp;
    this->cargosRoomService = 0.0;
}

void Renta::agregarCargosRoomService(float costoAdicional) {
    this->cargosRoomService += costoAdicional;
    this->costoTotal += costoAdicional; // Se suma al costo total de la renta
}

string Renta::getCodigoHabitacion() 
{ 
    return codigoHabitacion; 
}

string Renta::getCodigoCliente() 
{ 
    return codigoCliente; 
}

int Renta::getDias() 
{ 
    return dias; 
}

float Renta::getCostoTotal() 
{ 
    return costoTotal; 
}

string Renta::getCodigoEmpleado() 
{ 
    return codigoEmpleado; 
}

// Modifica mostrarDetalles para que el gerente vea qué se cobró
void Renta::mostrarDetalles() {
    cout << "--- DETALLE DE RENTA ---" << endl;
    cout << "Habitacion: " << codigoHabitacion << endl;
    cout << "Cliente: " << codigoCliente << endl;
    cout << "Dias: " << dias << endl;
    if (cargosRoomService > 0) {
        cout << "Cargos Extra (Room Service): $" << cargosRoomService << endl;
    }
    cout << "Costo Total Final: $" << costoTotal << endl;
    cout << "Atendido por Empleado: " << codigoEmpleado << endl;
}