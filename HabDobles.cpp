#pragma once
#include <iostream>
#include "Habitacion.cpp"
using namespace std;

class HabDobles : public Habitacion {
    public:
    HabDobles(string codigo);
    string getTipoHabitacion();
};

HabDobles::HabDobles(string codigo) {
    this->codigoHabitacion = codigo;
    this->precioRenta = 800.0;
}

string HabDobles::getTipoHabitacion() {
    return "Doble";
}