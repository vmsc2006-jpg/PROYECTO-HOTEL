#include <iostream>
using namespace std;

class Persona{
    protected:
    string nombre;
    string direccion;
    string telefono;
    string rfc;

    public:
    Persona();

    void setNombre(string nombre);
    string getNombre();

    void setDireccion(string direccion);
    string getDireccion();

    void setTelefono(string telefono);
    string getTelefono();

    void setRFC(string rfc);
    string getRFC();

    // Metodo virtual de polimorfismo
    virtual void mostrarDatos(){}
};

Persona::Persona(){
    nombre = "";
    direccion = "";
    telefono = "";
    rfc = "";
}
void Persona::setNombre(string nombre){
    this -> nombre = nombre;
}
string Persona::getNombre(){
    return this-> nombre;
}

void Persona::setDireccion(string direccion){
    this -> direccion = direccion;
}
string Persona::getDireccion(){
    return this -> direccion;
}

void Persona::setTelefono(string telefono){
    this ->telefono = telefono;
}
string Persona::getTelefono(){
    return this -> telefono;
}

void Persona::setRFC(string rfc){
    this -> rfc = rfc;
}
string Persona::getRFC(){
    return this ->  rfc;
}