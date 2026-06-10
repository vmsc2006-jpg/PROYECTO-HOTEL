#pragma once
#include <iostream>
#include "Habitacion.cpp"
using namespace std;

class HabLujo : public Habitacion {
    public:
    HabLujo(string codigo);
    string getTipoHabitacion();
};

HabLujo::HabLujo(string codigo) {
    this->codigoHabitacion = codigo;
    this->precioRenta = 1500.0;
}

string HabLujo::getTipoHabitacion() {
    return "De Lujo (5 personas)";
}