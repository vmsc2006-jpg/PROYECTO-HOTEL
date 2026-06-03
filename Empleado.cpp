#include <iostream>
using namespace std;

class Empleado : public Persona{
    protected:
    string codigoEmpleado;
    string puesto;

    public:
    Empleado();

    void setCodigoEmpleado(string);
    string getCodigoEmpleado();

    void setPuesto(string);
    string getPuesto();

    //metodo virtual de polimorfismo
    virtual float calcularSalario() = 0;
};

Empleado::Empleado(){
    codigoEmpleado = "";
    puesto = "";
}

void Empleado::setCodigoEmpleado(string codigoEmpleado){
    this -> codigoEmpleado = codigoEmpleado;
}
string Empleado::getCodigoEmpleado(){
    return this -> codigoEmpleado;
}

void Empleado::setPuesto(string puesto){
    this -> puesto = puesto;
}
string Empleado::getPuesto(){
    return this -> puesto;
}