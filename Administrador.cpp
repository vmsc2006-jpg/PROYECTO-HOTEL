#include <iostream>
using namespace std;

class Administrador : public Empleado{
    private:
    int huespedesAtendidos;

    public:
    Administrador();

    void setHuespedesAtendidos(int);
    int getHuespedesAtendidos();

    float calcularSalario();
    void mostrarDatos();
};

Administrador::Administrador(){
    huespedesAtendidos = 0;
}

void Administrador::setHuespedesAtendidos(int huespedesAtendidos){
    this -> huespedesAtendidos = huespedesAtendidos;
}
int Administrador::getHuespedesAtendidos(){
    return this -> huespedesAtendidos;
}

float Administrador::calcularSalario(){
    return 8000 + comision;  
}

void Administrador::mostrarDatos(){
    cout<<"---ADMINISTRADOR---"<<endl;
    cout<<"Nombre: "<<getNombre()<<endl;
    cout<<"Direccion: "<<getDireccion()<<endl;
    cout<<"Telefono: "<<getTelefono()<<endl;
    cout<<"RFC: "<<getRFC()<<endl;
    cout<<"Codigo: "<<getCodigoEmpleado()<<endl;
    cout<<"Puesto: "<<getPuesto()<<endl;
    cout<<"Salario: "<<calcularSalario()<<endl;
    cout<<"Huespedes atendidos: "<<huespedesAtendidos<<endl;
}
 