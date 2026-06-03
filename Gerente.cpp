#include <iostream>
using namespace std;

class Gerente : public Empleado{
    public:
    Gerente();

    float calcularSalario();
    void mostrarDatos();
};

Gerente::Gerente(){}

float Gerente::calcularSalario(){
    return 25000;
}

void Gerente::mostrarDatos(){
    cout<<"---GERENTE---"<<endl;
    cout<<"Nombre: "<<getNombre()<<endl;
    cout<<"Direccion: "<<getDireccion()<<endl;
    cout<<"Telefono: "<<getTelefono()<<endl;
    cout<<"RFC: "<<getRFC()<<endl;
    cout<<"Codigo: "<<getCodigoEmpleado()<<endl;
    cout<<"Puesto: "<<getPuesto()<<endl;
    cout<<"Salario: "<<calcularSalario()<<endl;
}