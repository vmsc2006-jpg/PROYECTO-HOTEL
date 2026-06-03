#include <iostream>
using namespace std;

class PersonalServicio : public Empleado{
    public:
    PersonalServicio();

    float calcularSalario();
    void mostrarDatos();
};

PersonalServicio::PersonalServicio(){}

float PersonalServicio::calcularSalario(){
    return 6000;
}

void PersonalServicio::mostrarDatos(){
    cout<<"---PERSONAL DE SERVICIO---"<<endl;
    cout<<"Nombre: "<<getNombre()<<endl;
    cout<<"Direccion: "<<getDireccion()<<endl;
    cout<<"Telefono: "<<getTelefono()<<endl;
    cout<<"RFC: "<<getRFC()<<endl;
    cout<<"Codigo: "<<getCodigoEmpleado()<<endl;
    cout<<"Puesto: "<<getPuesto()<<endl;
    cout<<"Salario: "<<calcularSalario()<<endl;
}