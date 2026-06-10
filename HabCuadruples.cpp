#pragma once
#include <iostream>
#include "Habitacion.cpp"
using namespace std;

class HabCuadruples : public Habitacion {
    public:
    HabCuadruples(string codigo);
    string getTipoHabitacion();
};

HabCuadruples::HabCuadruples(string codigo) {
    this->codigoHabitacion = codigo;
    this->precioRenta = 1200.0;
}

string HabCuadruples::getTipoHabitacion() {
    return "Cuadruple";
}