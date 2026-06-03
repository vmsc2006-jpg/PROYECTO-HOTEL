#include <iostream>
using namespace std;

class Cliente : public Persona{
    private:
    string correo;
    string codigoHuesped;

    public:
    Cliente();

    void setCorreo(string);
    string getCorreo();

    void setCodigoHuesped(string);
    string getCodigoHuesped();

    void mostrarDatos();
};

Cliente::Cliente(){
    correo = "";
    codigoHuesped = "";
}

void Cliente::setCorreo(string correo){
    this -> correo = correo;
}
string Cliente::getCorreo(){
    return this -> correo;
}

void Cliente::setCodigoHuesped(string codigoHuesped){
    this -> codigoHuesped = codigoHuesped;
}
string Cliente::getCodigoHuesped(){
    return this -> codigoHuesped;
}

void Cliente::mostrarDatos(){
    cout<<"---CLIENTE---"<<endl;
    cout<<"Nombre: "<<getNombre()<<endl;
    cout<<"Direccion: "<<getDireccion()<<endl;
    cout<<"Telefono: "<<getTelefono()<<endl;
    cout<<"RFC: "<<getRFC()<<endl;
    cout<<"Correo electronico: "<<correo<<endl;
    cout<<"Codigo de huesped: "<<codigoHuesped<<endl;
}